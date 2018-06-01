from pycparser import c_parser, c_ast, parse_file, c_generator

generator = c_generator.CGenerator()

#files = ['barrier.c', 'critical.c', 'loop.c', 'loop_ull.c', 'ordered.c',
#         'parallel.c', 'sections.c', 'single.c']
files = ['task.c', 'target.c']
# excluded files with errors: task.c target.c


class Visitor(c_ast.NodeVisitor):
    def visit_FuncDef(self, node):

        func_name = node.decl.name

        if not str(func_name).startswith('GOMP_'):
            return

        decl = node.children()[0]
        x = decl[1]
        funcdecl = x.type
        args = funcdecl.children()[0][1]

        str_function_type = generator.visit(decl[1].type.type)
        #param_list_str = generator.visit_ParamList(args)

        print((str_function_type +
               ' PRE_' + func_name + '();').replace("_Bool", "bool"))
        print((str_function_type +
               ' POST_' + func_name + '();').replace("_Bool", "bool"))
        print('')

for f in files:
    print('\n/* ' + f + ' */')

    ast = parse_file('src/{0}.out'.format(f))
    fdv = Visitor()
    fdv.visit(ast)
