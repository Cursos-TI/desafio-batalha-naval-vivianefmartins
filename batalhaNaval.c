#include <stdio.h> // Inclui a biblioteca padrão de entrada e saída, necessária para funções como printf.

int main() { // Função principal, onde a execução do programa começa.
    
    // Declara um array de caracteres chamado 'linha' de tamanho 10.
    // Inicializa o array com as letras de 'A' a 'J', que serão usadas como rótulos das colunas do tabuleiro.
    char linha[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    
    // Declara uma matriz de inteiros chamada 'tabuleiro' com 10 linhas e 10 colunas.
    // Esta matriz representará o tabuleiro do jogo Batalha Naval.
    int tabuleiro[10][10];
    
    // Declara variáveis inteiras 'i' e 'j', que serão usadas como contadores em laços (loops).
    int i, j;

    //inicializando o tabuleiro com água (0)
    // Inicia um laço 'for' que percorrerá as linhas do tabuleiro (de 0 a 9).
    for(i = 0; i < 10; i++) {
        // Inicia um laço 'for' aninhado que percorrerá as colunas do tabuleiro (de 0 a 9) para cada linha.
        for(j = 0; j < 10; j++) {
            // Atribui o valor 0 (representando água) à célula atual [i][j] do tabuleiro.
            tabuleiro[i][j]= 0;
        }
        // Fim do laço interno (colunas).
    }
    // Fim do laço externo (linhas).

    
    //Navio 1: Horizontal
    // Define a linha inicial (índice 2) onde o Navio 1 será colocado.
    int navio1_linhaInicial = 2;
    // Define a coluna inicial (índice 1) onde o Navio 1 será colocado.
    int navio1_colunaInicial = 1;

    
    //coloca o navio no tabuleiro
    // Inicia um laço 'for' para posicionar as 3 partes do Navio 1.
    for(int k = 0; k < 3; k++) {
        // Calcula a coluna atual para esta parte do navio. Como é horizontal, a coluna aumenta a cada iteração.
        int colunaAtual = navio1_colunaInicial + k;
        // Verifica se a 'colunaAtual' está dentro dos limites do tabuleiro (menor que 10).
        if(colunaAtual < 10) {
            // Coloca uma parte do navio (valor 3) na posição [linhaInicial][colunaAtual] do tabuleiro.
            tabuleiro[navio1_linhaInicial][colunaAtual] = 3;
        } else { // Caso contrário (se a parte do navio sair do tabuleiro)...
            // Imprime uma mensagem de erro indicando que parte do navio saiu do tabuleiro.
            printf("ERRO: Parte do Navio 1 saiu do tabuleiro na coluna %d.\n", colunaAtual);
        }
        // Fim do 'if/else'.
    }
    // Fim do laço de posicionamento do Navio 1.

    
    //Navio 2: Vertical
    // Define a linha inicial (índice 5) onde o Navio 2 será colocado.
    int navio2_linhaInicial = 5;
    // Define a coluna inicial (índice 5) onde o Navio 2 será colocado.
    int navio2_colunaInicial = 5;

    //coloca o navio no tabuleiro
    // Declara uma variável 'sobreposicao' e a inicializa com 0.
    int sobreposicao = 0; 
    
    // Inicia um laço 'for' para posicionar as 3 partes do Navio 2.
    for(int k = 0; k < 3; k++) {
        // Calcula a linha atual para esta parte do navio. Como é vertical, a linha aumenta a cada iteração.
        int linhaAtual = navio2_linhaInicial + k;
        // Verifica se a 'linhaAtual' está dentro dos limites do tabuleiro (menor que 10).
        if(linhaAtual < 10) {
            // Verifica se a posição atual no tabuleiro já está ocupada por outro navio (valor 3).
            if(tabuleiro[linhaAtual][navio2_colunaInicial] == 3) {
                // Se houver sobreposição, imprime uma mensagem de erro.
                printf("ERRO: Navio 2 sobrepoe Navio 1 na posicao [%d][%d].\n", linhaAtual, navio2_colunaInicial);
            }
            // Coloca uma parte do navio (valor 3) na posição atual.
            tabuleiro[linhaAtual][navio2_colunaInicial] = 3;
        } else { // Caso contrário (se a parte do navio sair do tabuleiro)...
            // Imprime uma mensagem de erro.
            printf("ERRO: Parte do Navio 2 saiu do tabuleiro na linha %d.\n", linhaAtual);
        }
        // Fim do 'if/else'.
    }
    // Fim do laço de posicionamento do Navio 2.

    //Navio 3: Diagonal - Baixo/Direita
    // Define a linha inicial (índice 4) para o Navio 3.
    int navio3_linhaInicial = 4;
    // Define a coluna inicial (índice 1) para o Navio 3.
    int navio3_colunaInicial = 1;

    // Inicia um laço 'for' para posicionar as 3 partes do Navio 3.
    for(int k = 0; k < 3; k++) {
        // Calcula a linha atual, aumentando a cada iteração (diagonal para baixo).
        int linhaAtual = navio3_linhaInicial + k;
        // Calcula a coluna atual, aumentando a cada iteração (diagonal para direita).
        int colunaAtual = navio3_colunaInicial + k;

        // Verifica se a 'linhaAtual' e 'colunaAtual' estão dentro dos limites do tabuleiro.
        if(linhaAtual >= 0 && linhaAtual < 10 && colunaAtual >=0 && colunaAtual < 10) {
            // Verifica se a posição atual no tabuleiro já está ocupada por outro navio.
            if(tabuleiro[linhaAtual][colunaAtual] == 3) {
                // Se houver sobreposição, imprime uma mensagem de erro.
                printf("ERRO: Navio 3 esta sobrepondo outro navio na posicao [%d][%d].\n", linhaAtual, colunaAtual);
            }
            // Coloca uma parte do navio (valor 3) na posição atual.
            tabuleiro[linhaAtual][colunaAtual] = 3;
        } else { // Caso contrário (se a parte do navio sair do tabuleiro)...
            // Imprime uma mensagem de erro.
            printf("ERRO: Parte do Navio 3 saiu do tabuleiro na posicao [%d][%d].\n", linhaAtual, colunaAtual);
        }
        // Fim do 'if/else'.
    }
    // Fim do laço de posicionamento do Navio 3.

    //Navio 4: Diagonal - Baixo/Esquerda
    // Define a linha inicial (índice 1) para o Navio 4.
    int navio4_linhaInicial = 1;
    // Define a coluna inicial (índice 8) para o Navio 4.
    int navio4_colunaInicial = 8; 

    // Inicia um laço 'for' para posicionar as 3 partes do Navio 4.
    for(int k = 0; k < 3; k++) {
        // Calcula a linha atual, aumentando a cada iteração (diagonal para baixo).
        int linhaInicial = navio4_linhaInicial + k; 
        // Calcula a coluna atual, diminuindo a cada iteração (diagonal para esquerda).
        int colunaInicial = navio4_colunaInicial - k; 

        // Verifica se a 'linhaInicial' e 'colunaInicial' (nomes locais) estão dentro dos limites do tabuleiro.
        if(linhaInicial >= 0 && linhaInicial < 10 && colunaInicial >= 0 && colunaInicial < 10) {
            // Verifica se a posição atual no tabuleiro já está ocupada por outro navio.
            if(tabuleiro[linhaInicial][colunaInicial] == 3) {
                // Se houver sobreposição, imprime uma mensagem de erro.
                printf("ERRO: O Navio 4 esta sobrepondo outro navio na posicao [%d][%d].\n", linhaInicial, colunaInicial);
            }
            // Coloca uma parte do navio (valor 3) na posição atual.
            tabuleiro[linhaInicial][colunaInicial] = 3;
        } else { // Caso contrário (se a parte do navio sair do tabuleiro)...
            // Imprime uma mensagem de erro.
            printf("ERRO: Navio 4 saiu do tabuleiro na posicao [%d][%d].\n", linhaInicial, colunaInicial);
        }
        // Fim do 'if/else'.
    }
    // Fim do laço de posicionamento do Navio 4.

    // Imprime uma linha em branco para formatação da saída.
    printf("\n");
    // Imprime o título do tabuleiro.
    printf("### TABULEIRO BATALHA NAVAL ###\n");
    // Imprime a legenda do tabuleiro.
    printf("Legenda: 0 = agua e 3 = partes do navio.\n");
    // Imprime outra linha em branco.
    printf("\n");
    // Imprime dois espaços para alinhar os rótulos das colunas.
    printf("  ");
    
    // Inicia um laço 'for' para imprimir os rótulos das colunas (A-J).
    for(j = 0; j < 10; j++) {
        // Imprime um espaço seguido pelo caractere do rótulo da coluna atual.
        printf(" %c", linha[j]);
    }
    // Fim do laço de impressão dos rótulos das colunas.
    // Imprime uma nova linha após os rótulos das colunas.
    printf("\n");

    // Inicia um laço 'for' para percorrer e imprimir cada linha do tabuleiro.
    for(i = 0; i < 10; i++) {
        // Imprime o número da linha atual (i+1, para mostrar de 1 a 10), formatado para ocupar 2 espaços.
        printf("%2d", i + 1);
        // Inicia um laço 'for' aninhado para percorrer e imprimir cada célula da linha atual.
        for(j = 0; j < 10; j++) {
            // Imprime um espaço antes do valor da célula para formatação.
            printf(" ");
            // Imprime o valor da célula atual [i][j] do tabuleiro (0 para água, 3 para navio).
            printf("%d", tabuleiro[i][j]);
        }
        // Fim do laço interno (células da linha).
        // Imprime uma nova linha ao final de cada linha do tabuleiro.
        printf("\n");
    }
    // Fim do laço externo (linhas do tabuleiro).
    
    // Retorna 0 para o sistema operacional, indicando que o programa foi executado com sucesso.
    return 0;
}
// Fim da função main.