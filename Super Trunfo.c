#include <stdio.h>
#include <string.h>

// Definição do tamanho máximo da string, incluindo o \0.
// 50 é o tamanho máximo do vetor cidade. Usamos (sizeof(cidade1) - 1) para o limite do fgets.
#define MAX_CIDADE_LEN 50 

void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    // Variáveis para a Carta 1
    char estado1;
    char codigo1[4];
    char cidade1[MAX_CIDADE_LEN]; // Usando o define
    int populacao1;
    float area1;
    float pib1;
    int pontos_turisticos1;
    
    // Variáveis para a Carta 2
    char estado2;
    char codigo2[4];
    char cidade2[MAX_CIDADE_LEN]; // Usando o define
    int populacao2;
    float area2;
    float pib2;
    int pontos_turisticos2;
    
    // Variável para a escolha do atributo
    int escolha_atributo;
    
    printf("=== SUPER TRUNFO DE ESTADOS ===\n");
    printf("Cadastro das Cartas\n\n");
    
    // CADASTRO DA CARTA 1
    printf("--- CARTA 1 ---\n");
    
    // Estado
    printf("Estado (A-H): ");
    scanf(" %c", &estado1);
    
    // Código da Carta
    printf("Codigo da Carta (ex: %c01): ", estado1);
    // Usamos "%3s" para ler exatamente 3 caracteres do código
    scanf("%3s", codigo1);
    
    // Nome da Cidade
    printf("Nome da Cidade: ");
    // Limpa o buffer após o scanf("%3s", codigo1)
    limpar_buffer(); 
    // fgets é mais seguro para ler strings longas com espaços
    fgets(cidade1, MAX_CIDADE_LEN, stdin);
    // Remove o '\n' que o fgets adiciona no final da string
    cidade1[strcspn(cidade1, "\n")] = 0; 
    
    // População
    printf("Populacao: ");
    scanf("%d", &populacao1);
    
    // Área
    printf("Area (km²): ");
    scanf("%f", &area1);
    
    // PIB
    printf("PIB (bilhoes): ");
    scanf("%f", &pib1);
    
    // Pontos Turísticos
    printf("Numero de Pontos Turisticos: ");
    scanf("%d", &pontos_turisticos1);
    
    printf("\n");
    
    // CADASTRO DA CARTA 2
    printf("--- CARTA 2 ---\n");
    
    // Estado
    printf("Estado (A-H): ");
    scanf(" %c", &estado2);
    
    // Código da Carta
    printf("Codigo da Carta (ex: %c01): ", estado2);
    scanf("%3s", codigo2);
    
    // Nome da Cidade
    printf("Nome da Cidade: ");
    // Limpa o buffer após o scanf anterior
    limpar_buffer(); 
    // Leitura da string com fgets
    fgets(cidade2, MAX_CIDADE_LEN, stdin);
    // Remove o '\n'
    cidade2[strcspn(cidade2, "\n")] = 0; 
    
    // População
    printf("Populacao: ");
    scanf("%d", &populacao2);
    
    // Área
    printf("Area (km²): ");
    scanf("%f", &area2);
    
    // PIB
    printf("PIB (bilhoes): ");
    scanf("%f", &pib2);
    
    // Pontos Turísticos
    printf("Numero de Pontos Turisticos: ");
    scanf("%d", &pontos_turisticos2);
    
    // EXIBIÇÃO DAS CARTAS CADASTRADAS
    printf("\n\n=== CARTAS CADASTRADAS ===\n");
    
    // Carta 1
    printf("\nCarta 1:\n");
    printf("Estado: %c\n", estado1);
    printf("Codigo: %s\n", codigo1);
    printf("Nome da Cidade: %s\n", cidade1);
    printf("Populacao: %d\n", populacao1);
    printf("Area: %.2f km²\n", area1);
    printf("PIB: %.2f bilhoes de reais\n", pib1);
    printf("Numero de Pontos Turisticos: %d\n", pontos_turisticos1);
    
    // Carta 2
    printf("\nCarta 2:\n");
    printf("Estado: %c\n", estado2);
    printf("Codigo: %s\n", codigo2);
    printf("Nome da Cidade: %s\n", cidade2);
    printf("Populacao: %d\n", populacao2);
    printf("Area: %.2f km²\n", area2);
    printf("PIB: %.2f bilhoes de reais\n", pib2);
    printf("Numero de Pontos Turisticos: %d\n", pontos_turisticos2);
    
    // --- LÓGICA DO JOGO ---
    printf("\n\n=== JOGO: ESCOLHA DO TRUNFO ===\n");
    printf("Escolha o atributo para a comparacao:\n");
    printf("1 - Populacao\n");
    printf("2 - Area\n");
    printf("3 - PIB\n");
    printf("4 - Numero de Pontos Turisticos\n");
    printf("Escolha (1-4): ");
    // Limpa o buffer após o último scanf antes de ler o próximo int
    limpar_buffer(); 
    scanf("%d", &escolha_atributo);
    
    printf("\n--- RESULTADO ---\n");
    
    switch (escolha_atributo) {
        case 1: // População
            printf("Atributo escolhido: Populacao\n");
            if (populacao1 > populacao2) {
                printf("Vencedora: Carta 1 (%s) com %d habitantes!\n", cidade1, populacao1);
            } else if (populacao2 > populacao1) {
                printf("Vencedora: Carta 2 (%s) com %d habitantes!\n", cidade2, populacao2);
            } else {
                printf("Empate! Ambas tem %d habitantes.\n", populacao1);
            }
            break;
            
        case 2: // Área
            printf("Atributo escolhido: Area\n");
            if (area1 > area2) {
                printf("Vencedora: Carta 1 (%s) com %.2f km²!\n", cidade1, area1);
            } else if (area2 > area1) {
                printf("Vencedora: Carta 2 (%s) com %.2f km²!\n", cidade2, area2);
            } else {
                printf("Empate! Ambas tem %.2f km².\n", area1);
            }
            break;
            
        case 3: // PIB
            printf("Atributo escolhido: PIB\n");
            if (pib1 > pib2) {
                printf("Vencedora: Carta 1 (%s) com %.2f bilhoes!\n", cidade1, pib1);
            } else if (pib2 > pib1) {
                printf("Vencedora: Carta 2 (%s) com %.2f bilhoes!\n", cidade2, pib2);
            } else {
                printf("Empate! Ambas tem %.2f bilhoes.\n", pib1);
            }
            break;
            
        case 4: // Pontos Turísticos
            printf("Atributo escolhido: Numero de Pontos Turisticos\n");
            if (pontos_turisticos1 > pontos_turisticos2) {
                printf("Vencedora: Carta 1 (%s) com %d pontos turisticos!\n", cidade1, pontos_turisticos1);
            } else if (pontos_turisticos2 > pontos_turisticos1) {
                printf("Vencedora: Carta 2 (%s) com %d pontos turisticos!\n", cidade2, pontos_turisticos2);
            } else {
                printf("Empate! Ambas tem %d pontos turisticos.\n", pontos_turisticos1);
            }
            break;
            
        default:
            printf("Escolha de atributo invalida. O jogo terminou sem comparacao.\n");
            break;
    }
    
    return 0;
}