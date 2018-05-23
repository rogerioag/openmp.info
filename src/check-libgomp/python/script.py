#Parsing SVN
#Usando python3
import os
import time

def gera_arquivos():
	svn_versao = os.popen("svn ls svn://gcc.gnu.org/svn/gcc/tags | grep \"^gcc_\"").readlines()
	arquivo_versoes = open("./arquivo_versoes.txt","w")
	lista_versoes = []
	for linha in svn_versao:
		linha_replace = linha.replace("\n", "")
		arquivo_versoes.write("svn://gcc.gnu.org/svn/gcc/tags/"+linha_replace+"libgomp/libgomp.map\n")
		lista_versoes.append(linha_replace)
	arquivo_versoes.close()
	info_versoes(lista_versoes)

def info_versoes(lista_versoes):
	arquivo_versoes = open("./arquivo_versoes.txt","r")
	arquivo_versoes_vazias = open("./versoes_vazias.txt","w")
	cont = 0
	for indice, valor in enumerate(arquivo_versoes):
		svn_info = os.popen("svn info "+valor).readlines()
		print(svn_info)
		if not svn_info:
			arquivo_versoes_vazias.write(lista_versoes[indice] + "  NÃO POSSUE libgomp\n")
		else:
			replace_arquivo_versoes = valor.replace("libgomp.map\n","")
			criar_pasta = os.popen("mkdir "+lista_versoes[indice])
			replace_lista_versoes = lista_versoes[indice].replace("e/","e")
			#print(replace_arquivo_versoes)
			#print(replace_lista_versoes)
			export = os.popen("svn export "+ replace_arquivo_versoes+ " ./"+replace_lista_versoes+" --force").readlines()
			arquivo_info = open(lista_versoes[indice]+"libgomp.info","w")
			for linha in svn_info:
				arquivo_info.write(linha)
		cont += 1
		print(cont)
	arquivo_versoes_vazias.close()
	arquivo_info.close()
	

if __name__ == '__main__':
	gera_arquivos()

#svn extract