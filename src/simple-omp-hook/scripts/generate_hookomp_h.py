from pycparser import c_parser, c_ast, parse_file, c_generator

generator = c_generator.CGenerator()

files = ['barrier.c', 'critical.c', 'loop.c', 'loop_ull.c', 'ordered.c',
         'parallel.c', 'sections.c', 'single.c']

         # excluded files with errors: task.c target.c


class Visitor1(c_ast.NodeVisitor):
    def visit_FuncDef(self, node):

        func_name = node.decl.name

        if not str(func_name).startswith('GOMP_'):
            return

        decl = node.children()[0]
        x = decl[1]
        funcdecl = x.type
        args = funcdecl.children()[0][1]

        str_function_type = generator.visit(decl[1].type.type)
        param_list_str = generator.visit_ParamList(args)

        print((str_function_type +
               ' (*lib_' + func_name + ')(' + param_list_str + ');').replace("_Bool", "bool"))


class Visitor2(c_ast.NodeVisitor):
    def visit_FuncDef(self, node):

        func_name = node.decl.name

        if not str(func_name).startswith('GOMP_'):
            return

        decl = node.children()[0]
        x = decl[1]
        funcdecl = x.type
        args = funcdecl.children()[0][1]

        str_function_type = generator.visit(decl[1].type.type)
        param_list_str = generator.visit_ParamList(args)

        print((str_function_type +
               ' ' + func_name + '(' + param_list_str + ');').replace("_Bool", "bool"))


for f in files:
    print('\n/* {} */\n'.format(f))
    ast = parse_file('src/{0}.out'.format(f))
    fdv = Visitor1()
    fdv.visit(ast)

for f in files:
    print('\n/* {} */\n'.format(f))
    ast = parse_file('src/{0}.out'.format(f))
    fdv = Visitor2()
    fdv.visit(ast)


