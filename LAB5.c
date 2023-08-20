#include <stdio.h>
#include <conio.h> 
#include <string.h>
#include <stdlib.h>

typedef struct Em_node {
    char name[10];
    int salary ;
    struct Em_node *Next ;
}Node_type;

typedef struct Em_node *NodePTR ;

typedef struct  {
    char name[10];
    int salary ;
}  info ;


NodePTR Colletor(info A){
    NodePTR N ;
    N = (NodePTR) calloc(10 , sizeof(Node_type));
    strcpy(N -> name,A.name);
    N -> salary = A.salary;
    N -> Next = NULL ;
    return(N);
}

NodePTR Reciver[2] ;

char *Cname(int Em_num,int criteria ){
    char name[10] ;
    int salary , count = 0 ;
    info A ; 
    for(int i = 0 ; i <= Em_num - 1 ; i++){
        printf("Enter Name %d : ",i+1);
        scanf("%s",A.name);
        printf("Enter salary %d : ",i+1);
        scanf("%d",&A.salary);
        Reciver[i] = Colletor(A);
    }
    printf("\t ================= \n\tEmployee Salary > %d\n",criteria);
    for (int j = 0; j <= Em_num - 1; j++){
        if (Reciver[j] -> salary > criteria){
            printf("%d. %s \n",++count,Reciver[j] -> name );
        }
    }
}

int main(void) {
    int Em_num , criteria ;
    printf("How many Employee : ");
    scanf("%d",&Em_num);
    printf(" Find Employee Salary > : ");
    scanf("%d",&criteria);
    printf("\t==Employee Salary==\n\t===================\n");
    Cname(Em_num , criteria );

    return 0 ;
};


