from pycparser import c_parser, c_ast, parse_file, c_generator

generator = c_generator.CGenerator()

#files = ['barrier.c', 'critical.c', 'loop.c', 'loop_ull.c', 'ordered.c',
#         'parallel.c', 'sections.c', 'single.c']
#files = ['../' + f for f in ['prepostdef.h']]
# excluded files with errors: task.c target.c

variables = []
print_results = []
pre = []
post = []
count = 0

class Visitor(c_ast.NodeVisitor):
    def visit_FuncDef(self, node):
        global count
        func_name = node.decl.name

        if not str(func_name).startswith('GOMP_'):
            return
        count += 1
        decl = node.children()[0]
        x = decl[1]
        funcdecl = x.type
        args = funcdecl.children()[0][1]

        str_function_type = generator.visit(decl[1].type.type)
        param_list_str = generator.visit_ParamList(args)

        variables.append('int num_{} = 0;'.format(func_name))

        # printf("Number of parallel regions: %d\n", num_parallel_regions);
        print_results.append('printf("Number of {}: %d\\n", num_{});'.format(func_name, func_name))

        

        args_str = ''

        for c in args.children():
            if not isinstance(c[1], c_ast.EllipsisParam):
                if c[1].name is not None:
                    args_str += c[1].name + ','
        args_str = '(' + args_str[:-1] + ')'

        pre_str = (str_function_type + ' PRE_' + func_name +
               '(' + param_list_str + ') {\n').replace("_Bool", "bool")
        
        pre_str += '\tPRINT_FUNC_NAME;\n'
        pre_str += '\tnum_{}++;\n'.format(func_name)
        pre_str += '}\n'
        pre.append(pre_str)

        post_str = (str_function_type + ' POST_' + func_name +
               '(' + param_list_str + ') {\n').replace("_Bool", "bool")
        
        post_str += '\tPRINT_FUNC_NAME;\n'
        
        post_str += '}\n'
        post.append(post_str)
        # print((str_function_type + ' ' + func_name +
        #        '(' + param_list_str + ')').replace("_Bool", "bool"))
        # print('{')
        # print('\tPRINT_FUNC_NAME;')
        # print('\tGET_RUNTIME_FUNCTION(lib_' + func_name + ', "' + func_name + '");')
        # print('\tTRACE("[hookomp]: Thread [%lu] is executing {}.\\n", (unsigned long int)pthread_self());'.format(
        #     func_name))
        # print('\tPRE_' + func_name + (args_str if args_str != '()' else '()') + ';')

        # if str_function_type != 'void':
        #     print('\t' + str_function_type.replace('_Bool', 'bool') +
        #           ' result = lib_' + func_name + args_str + ';')
        # else:
        #     print('\tlib_' + func_name + args_str + ';')

        # print('\tPOST_' + func_name  + (args_str if args_str != '()' else '()') + ';')

        # if str_function_type != 'void':
        #     print('\treturn result;')
        # print('}\n')

        # print('/* ------------------------------------------------------------- */')




ast = parse_file('src/all_functions.c')
fdv = Visitor()
fdv.visit(ast)

#for i in range (len(variables)):
    #print(variables[i])
print('count: ', count)   