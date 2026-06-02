/**
 * ============================================================================
 * SISTEMA DE MOVIMENTAÇÃO DE XADREZ - MATECHECK
 * ============================================================================
 * 
 * Este programa implementa a movimentação de peças de xadrez conforme os
 * níveis do desafio MateCheck, demonstrando diferentes estruturas de
 * repetição, recursividade e boas práticas de programação.
 * 
 * Autor: Assistente de Código
 * Versão: 1.0
 * Data: 2024
 * 
 * ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ============================================================================
 * CONSTANTES GLOBAIS
 * ============================================================================ */
#define MOVIMENTOS_BISPO 5      // Número de movimentos do bispo
#define MOVIMENTOS_TORRE 5      // Número de movimentos da torre
#define MOVIMENTOS_RAINHA 8     // Número de movimentos da rainha
#define MOVIMENTOS_CAVALO_L 2   // Movimentos em L do cavalo (composição)

/* ============================================================================
 * PROTÓTIPOS DAS FUNÇÕES
 * ============================================================================ */

// Nível Novato
void novato_mover_bispo(void);
void novato_mover_torre(void);
void novato_mover_rainha(void);

// Nível Aventureiro
void aventureiro_mover_cavalo(void);

// Nível Mestre (Recursivo)
void mestre_mover_bispo_recursivo(int passos);
void mestre_mover_torre_recursivo(int passos);
void mestre_mover_rainha_recursivo(int passos);
void mestre_mover_cavalo_loops_avancados(void);

// Funções utilitárias
void exibir_cabecalho(const char *nivel, const char *peca);
void linha_separadora(char caractere, int tamanho);
void pausar_tela(void);

/* ============================================================================
 * FUNÇÕES DE UTILITÁRIO
 * ============================================================================ */

/**
 * @brief Exibe um cabeçalho formatado para cada seção do programa
 * @param nivel Nível do desafio (Novato, Aventureiro, Mestre)
 * @param peca Nome da peça sendo movimentada
 */
void exibir_cabecalho(const char *nivel, const char *peca) {
    printf("\n");
    linha_separadora('=', 60);
    printf("\n🏆 NÍVEL %s - %s\n", nivel, peca);
    linha_separadora('-', 60);
    printf("\n");
}

/**
 * @brief Desenha uma linha separadora com caractere específico
 * @param caractere Caractere a ser repetido
 * @param tamanho Número de vezes que o caractere será repetido
 */
void linha_separadora(char caractere, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%c", caractere);
    }
    printf("\n");
}

/**
 * @brief Pausa a execução do programa até que o usuário pressione Enter
 */
void pausar_tela(void) {
    printf("\nPressione ENTER para continuar...");
    while (getchar() != '\n');
    getchar();
}

/* ============================================================================
 * NÍVEL NOVATO - ESTRUTURAS DE REPETIÇÃO SIMPLES
 * ============================================================================ */

/**
 * @brief Move o bispo 5 casas na diagonal superior direita
 * 
 * Utiliza a estrutura de repetição FOR para executar os movimentos.
 * A diagonal é composta pela combinação de duas direções básicas.
 */
void novato_mover_bispo(void) {
    exibir_cabecalho("NOVATO", "BISPO (Diagonal Superior Direita)");
    
    printf("🎯 Movendo Bispo para diagonal superior direita:\n");
    printf("   (Combinação: CIMA + DIREITA)\n\n");
    
    for (int passo = 1; passo <= MOVIMENTOS_BISPO; passo++) {
        printf("Passo %d: Cima\n", passo);
        printf("         Direita\n");
    }
    
    printf("\n✅ Bispo movimentou %d casas na diagonal.\n", MOVIMENTOS_BISPO);
}

/**
 * @brief Move a torre 5 casas para a direita
 * 
 * Utiliza a estrutura de repetição WHILE para executar os movimentos.
 */
void novato_mover_torre(void) {
    exibir_cabecalho("NOVATO", "TORRE (Direita)");
    
    printf("🎯 Movendo Torre para a direita:\n\n");
    
    int passo = 1;
    while (passo <= MOVIMENTOS_TORRE) {
        printf("Passo %d: Direita\n", passo);
        passo++;
    }
    
    printf("\n✅ Torre movimentou %d casas para a direita.\n", MOVIMENTOS_TORRE);
}

/**
 * @brief Move a rainha 8 casas para a esquerda
 * 
 * Utiliza a estrutura de repetição DO-WHILE para executar os movimentos,
 * garantindo que pelo menos um movimento seja executado.
 */
void novato_mover_rainha(void) {
    exibir_cabecalho("NOVATO", "RAINHA (Esquerda)");
    
    printf("🎯 Movendo Rainha para a esquerda:\n\n");
    
    int passo = 1;
    do {
        printf("Passo %d: Esquerda\n", passo);
        passo++;
    } while (passo <= MOVIMENTOS_RAINHA);
    
    printf("\n✅ Rainha movimentou %d casas para a esquerda.\n", MOVIMENTOS_RAINHA);
}

/* ============================================================================
 * NÍVEL AVENTUREIRO - LOOPS ANINHADOS
 * ============================================================================ */

/**
 * @brief Move o cavalo em formato "L" para baixo e esquerda
 * 
 * Utiliza loops aninhados: FOR para as duas casas para baixo (vertical)
 * e WHILE para uma casa para esquerda (horizontal).
 * O padrão L: ↓ ↓ ←
 */
void aventureiro_mover_cavalo(void) {
    exibir_cabecalho("AVENTUREIRO", "CAVALO (Movimento em L)");
    
    printf("🎯 Movendo Cavalo - Padrão em L (2 casas para baixo + 1 esquerda):\n");
    printf("   Representação: ↓ ↓ ←\n\n");
    
    // Primeira parte do movimento L: duas casas para baixo (movimento vertical)
    printf("--- FASE 1: Movimento Vertical (2 casas para baixo) ---\n");
    for (int i = 1; i <= 2; i++) {
        printf("Passo %d do cavalo: Baixo\n", i);
        
        // Pequena pausa visual entre os passos
        if (i < 2) {
            printf("   (Avançando...)\n");
        }
    }
    
    // Segunda parte do movimento L: uma casa para esquerda (movimento horizontal)
    printf("\n--- FASE 2: Movimento Horizontal (1 casa esquerda) ---\n");
    int passos_esquerda = 1;
    while (passos_esquerda <= 1) {
        printf("Passo final: Esquerda\n");
        passos_esquerda++;
    }
    
    printf("\n✅ Cavalo completou o movimento em L com sucesso!\n");
    printf("   (Total: 2 casas para baixo + 1 para esquerda)\n");
}

/* ============================================================================
 * NÍVEL MESTRE - FUNÇÕES RECURSIVAS E LOOPS AVANÇADOS
 * ============================================================================ */

/**
 * @brief Move o bispo recursivamente na diagonal superior direita
 * @param passos Número de passos restantes para movimentar
 *
 * Utiliza recursividade juntamente com loops aninhados para cada passo
 * do movimento diagonal (CIMA + DIREITA).
 */
void mestre_mover_bispo_recursivo(int passos) {
    // Caso base: quando não há mais passos para executar
    if (passos <= 0) {
        return;
    }
    
    // Loop aninhado para representar as duas direções do movimento diagonal
    for (int parte = 1; parte <= 1; parte++) {
        for (int direcao = 1; direcao <= 2; direcao++) {
            if (direcao == 1) {
                printf("Passo %d: Cima\n", MOVIMENTOS_BISPO - passos + 1);
            } else {
                printf("         Direita\n");
            }
        }
    }
    
    // Chamada recursiva para o próximo passo
    mestre_mover_bispo_recursivo(passos - 1);
}

/**
 * @brief Move a torre recursivamente para a direita
 * @param passos Número de passos restantes para movimentar
 */
void mestre_mover_torre_recursivo(int passos) {
    if (passos <= 0) {
        return;
    }
    
    printf("Passo %d: Direita\n", MOVIMENTOS_TORRE - passos + 1);
    mestre_mover_torre_recursivo(passos - 1);
}

/**
 * @brief Move a rainha recursivamente para a esquerda
 * @param passos Número de passos restantes para movimentar
 */
void mestre_mover_rainha_recursivo(int passos) {
    if (passos <= 0) {
        return;
    }
    
    printf("Passo %d: Esquerda\n", MOVIMENTOS_RAINHA - passos + 1);
    mestre_mover_rainha_recursivo(passos - 1);
}

/**
 * @brief Move o cavalo utilizando loops avançados com variáveis múltiplas
 * 
 * Implementa o movimento em L utilizando loops aninhados com controle
 * avançado, incluindo continue e break.
 * Padrão: 2 casas para cima + 1 para direita
 */
void mestre_mover_cavalo_loops_avancados(void) {
    exibir_cabecalho("MESTRE", "CAVALO (Loop Avançado - Cima + Direita)");
    
    printf("🎯 Movendo Cavalo - Padrão em L avançado:\n");
    printf("   (2 casas para cima + 1 para direita | Loops aninhados com controle)\n\n");
    
    int movimento_vertical = 0;
    int movimento_horizontal = 0;
    
    // Loop externo para controlar a fase do movimento
    for (int fase = 1; fase <= 2; fase++) {
        
        if (fase == 1) {
            printf("--- FASE %d: Movimento Vertical (Cima) ---\n", fase);
            
            // Loop interno com múltiplas condições para movimento vertical
            for (int i = 1; i <= 3; i++) {
                
                // Usando continue para pular iterações desnecessárias
                if (i > 2) {
                    printf("   (Atingido limite vertical, saindo do loop...)\n");
                    continue;  // Pula a iteração quando i > 2
                }
                
                movimento_vertical++;
                printf("Movimento vertical %d: Cima\n", movimento_vertical);
                
                // Pequena pausa visual entre movimentos
                if (movimento_vertical < 2) {
                    printf("   (Continuando subida...)\n");
                }
            }
            
        } else if (fase == 2) {
            printf("\n--- FASE %d: Movimento Horizontal (Direita) ---\n", fase);
            
            // Loop com break condicional para movimento horizontal
            for (int j = 1; j <= 5; j++) {
                movimento_horizontal++;
                printf("Movimento horizontal %d: Direita\n", movimento_horizontal);
                
                // Break quando atingir o número desejado de movimentos
                if (movimento_horizontal >= 1) {
                    printf("   (Movimento horizontal concluído!)\n");
                    break;  // Sai do loop após o primeiro movimento horizontal
                }
            }
        }
    }
    
    printf("\n✅ Cavalo completou movimento em L: ");
    printf("2 casas para CIMA + 1 para DIREITA\n");
    printf("   (Utilizou: continue para pular iterações | break para sair do loop)\n");
}

/**
 * @brief Executa todos os movimentos do Nível Mestre (recursivos)
 */
void executar_nivel_mestre(void) {
    // Bispo - Movimento recursivo
    exibir_cabecalho("MESTRE", "BISPO (Recursivo)");
    printf("🎯 Movendo Bispo recursivamente - Diagonal Superior Direita:\n\n");
    mestre_mover_bispo_recursivo(MOVIMENTOS_BISPO);
    printf("\n✅ Bispo movimentou %d casas na diagonal (recursão).\n", MOVIMENTOS_BISPO);
    
    // Torre - Movimento recursivo
    exibir_cabecalho("MESTRE", "TORRE (Recursivo)");
    printf("🎯 Movendo Torre recursivamente - Direita:\n\n");
    mestre_mover_torre_recursivo(MOVIMENTOS_TORRE);
    printf("\n✅ Torre movimentou %d casas para direita (recursão).\n", MOVIMENTOS_TORRE);
    
    // Rainha - Movimento recursivo
    exibir_cabecalho("MESTRE", "RAINHA (Recursivo)");
    printf("🎯 Movendo Rainha recursivamente - Esquerda:\n\n");
    mestre_mover_rainha_recursivo(MOVIMENTOS_RAINHA);
    printf("\n✅ Rainha movimentou %d casas para esquerda (recursão).\n", MOVIMENTOS_RAINHA);
    
    // Cavalo - Loops avançados
    mestre_mover_cavalo_loops_avancados();
}

/* ============================================================================
 * FUNÇÃO PRINCIPAL - MAIN
 * ============================================================================ */

/**
 * @brief Função principal que coordena a execução de todos os níveis
 * @return 0 para execução bem-sucedida
 */
int main(void) {
    
    // Configuração inicial
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif
    
    // Título principal
    printf("\n");
    linha_separadora('=', 60);
    printf("\n🐎 DESAFIO MATECHECK - SISTEMA DE MOVIMENTAÇÃO DE XADREZ 🏆\n");
    linha_separadora('=', 60);
    printf("\n📌 Este programa demonstra diferentes técnicas de programação:\n");
    printf("   - Estruturas de repetição (for, while, do-while)\n");
    printf("   - Loops aninhados\n");
    printf("   - Recursividade\n");
    printf("   - Controle de fluxo avançado (continue/break)\n");
    linha_separadora('-', 60);
    
    /* ======================================================================
     * NÍVEL 1: NOVATO
     * ==================================================================== */
    printf("\n🌟 INICIANDO NÍVEL NOVATO...\n");
    linha_separadora('-', 60);
    
    novato_mover_bispo();
    pausar_tela();
    
    novato_mover_torre();
    pausar_tela();
    
    novato_mover_rainha();
    pausar_tela();
    
    /* ======================================================================
     * NÍVEL 2: AVENTUREIRO
     * ==================================================================== */
    printf("\n🌟 INICIANDO NÍVEL AVENTUREIRO...\n");
    linha_separadora('-', 60);
    
    aventureiro_mover_cavalo();
    pausar_tela();
    
    /* ======================================================================
     * NÍVEL 3: MESTRE
     * ==================================================================== */
    printf("\n🌟 INICIANDO NÍVEL MESTRE...\n");
    linha_separadora('-', 60);
    
    executar_nivel_mestre();
    
    /* ======================================================================
     * CONCLUSÃO
     * ==================================================================== */
    printf("\n");
    linha_separadora('=', 60);
    printf("\n🎉 PARABÉNS! Todos os níveis foram concluídos com sucesso! 🎉\n");
    printf("\n📊 RESUMO DAS TÉCNICAS UTILIZADAS:\n");
    printf("   ✅ Nível Novato: for, while, do-while\n");
    printf("   ✅ Nível Aventureiro: loops aninhados\n");
    printf("   ✅ Nível Mestre: funções recursivas, continue, break\n");
    printf("\n🔧 Manutenibilidade:\n");
    printf("   - Código modular com funções específicas\n");
    printf("   - Constantes para valores numéricos\n");
    printf("   - Documentação completa (Doxygen style)\n");
    printf("   - Nomes de variáveis autoexplicativos\n");
    linha_separadora('=', 60);
    printf("\n");
    
    return 0;
}