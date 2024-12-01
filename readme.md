# Get Next Line

Este é o projeto "get_next_line" da Ecole 42. O objetivo deste projeto é criar uma função em C que lê uma linha de um descritor de arquivo por vez.

## Estrutura do Repositório

O repositório está organizado em duas pastas principais:

1. **Versão Antiga**: Contém a implementação original do projeto, sem o uso de listas linkadas.
2. **Nova Versão**: Contém a implementação atualizada do projeto, utilizando listas linkadas para melhorar a organização do código.

## Arquivos

### Versão Antiga
- `get_next_line.c`: Implementação da função `get_next_line` sem listas linkadas.
- `get_next_line_utils.c`: Funções auxiliares utilizadas na implementação da versão antiga.
- `get_next_line.h`: Arquivo de cabeçalho com as definições e protótipos das funções.

### Nova Versão
- `get_next_line.c`: Implementação da função `get_next_line` utilizando listas linkadas.
- `get_next_line_utils.c`: Funções auxiliares utilizadas na implementação da nova versão.
- `get_next_line.h`: Arquivo de cabeçalho com as definições e protótipos das funções.

## Como Compilar

Para compilar o projeto, você pode usar o seguinte comando:

```sh
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=32 get_next_line.c get_next_line_utils.c -o get_next_line
```

Substitua `BUFFER_SIZE` pelo tamanho do buffer que você deseja utilizar.

## Como Usar

Após compilar, você pode executar o programa passando um arquivo como argumento:

```sh
./get_next_line <nome_do_arquivo>
```

## Testes

Para testar a função `get_next_line`, você pode criar arquivos de teste com diferentes conteúdos e verificar se a função lê as linhas corretamente.

## Contribuição

Sinta-se à vontade para contribuir com melhorias ou correções. Para isso, faça um fork do repositório, crie uma branch para suas alterações e envie um pull request.

## Licença

Este projeto está licenciado sob a licença MIT. Veja o arquivo `LICENSE` para mais detalhes.
