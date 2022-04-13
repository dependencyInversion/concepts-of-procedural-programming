#include <stdio.h>
#include <string.h>

struct Article 
{
    char name[50];
    float price;
};

void WriteArticleToConsole(struct Article articles[])
{
    struct Article currentArticle;
    
    for (int i = 0; i < 2; i++) {
        currentArticle = articles[i];
        printf(
            "%d) %s (%.2f Euro)\n",
            i+1,
            currentArticle.name,
            currentArticle.price);
    }  
}

int main()
{
    struct Article a1, a2;
    int indexOfRequestedArticle = -1;
    float price= 0.0;
    float depositedSum = 0.0;
    float currentDeposit = 0.0;
    float refund = 0.0;
    
    strcpy(a1.name, "Wasser");
    a1.price = 0.5;
    strcpy(a2.name, "Limonade");
    a2.price = 1.0;
    
    struct Article articles[] = {
        a1,
        a2
    };
    
    WriteArticleToConsole(articles);
    
    printf("Geben Sie eine Zahl ein: ");
    scanf("%d", &indexOfRequestedArticle);
    
    price = articles[indexOfRequestedArticle - 1].price;
    
    printf("Preis: %.2f\n", price);
    
    
    do {
        printf("Eingeworfener Betrag: ");
        scanf("%f", &currentDeposit);
        if (currentDeposit > 0.0)
            depositedSum += currentDeposit;
    } while(depositedSum < price);
    
    refund = depositedSum - price;
    
    printf("Geld zurueck: %.2f\n", refund);
    
    printf("Getraenk entnhmen!\n");

    return 0;
}
