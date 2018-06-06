
# Script para extrair as funções do arquivo libgomp_g.h

## Funcionamento

1. Extrai os nomes das funções do arquivo ```libgomp_g.h``` utilizando o **ctags**
2. Baixa os arquivos ```.c``` do repositório **libgomp**
3. Extrai os nomes e o protótipo de todas as funções dos arquivos ```.c```
4. Filtra as funções ```GOMP_``` e ```GOACC_```
5. Utiliza o ```pycparser``` para gerar uma string de chamada de função
- Essa string será utilizada no arquivo ```hookomp.c``` para chamar a função original
- Utilizado o ```pycparser``` pois tem alguns protótipos mais complexos de extrair os nomes dos parâmetros, por exemplo:
```
void GOMP_taskloop (void (*fn) (void *), void *data, void (*cpyfn) (void *, void *), long arg_size, long arg_align, unsigned flags, unsigned long num_tasks, int priority, TYPE start, TYPE end, TYPE  ep)

```
6. Salva o nome do arquivo, nome da função, protótipo e string de chamada em um array, que será utilizado para gerar o código

## Compilar ctags

1. ```cd ctags```
2. ```./autogen```
3. ```./configure```
4. ```make```
5. ```sudo make install```

## Instalar pycparser

1. ```pip3 install pycparser```

## Uso
1. ```./generate_ctags.sh```
2. ```python3 parse_tag.py```