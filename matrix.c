#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// �Լ� ����
int** makeMatrix(int row, int col);
int fillNumber(int** matrix, int row, int col);
int addMatrix(int** matrixA, int** matrixB, int row, int col);
int subtractMatrix(int** matrixA, int** matrixB, int row, int col);
int transposeMatrix(int** matrixA, int** matrixT, int row, int col);
int multiplyMatrix(int** matrixA, int** matrixB, int row, int col);
void printMatrix(int** matrix, int row, int col);
int freeMatrix(int** matrix, int row, int col);

int main(){
    int row, col; //��� �� ����
    int num; //�Է¹��� ���� ����
    srand(time(NULL)); //�����Լ� �ʱ�ȭ
    printf("[----- [������] [2020039104] -----]\n\n");

    printf("��� ���� ���� �Է��Ͻÿ� : ");
    scanf("%d %d", &row, &col); //��� �� �Է¹ޱ�

    //��� ����
    int **matrixA = makeMatrix(row, col);
    int **matrixB = makeMatrix(row, col);
    int **matrixT = makeMatrix(row, col);

    printf("\n��� ���� �Ϸ�\n\n");

    while(num!=7){
        printf("************************************************\n");
        printf("1. ��� �� �����ϰ� ä���\n");
        printf("2. ��� ����\n");
        printf("3. ��� ����\n");
        printf("4. ��� ��ġ\n");
        printf("5. ��� ����\n");
        printf("6. ��� ���\n");
        printf("7. ����\n");
        printf("************************************************\n\n");

        printf("���ϴ� ��ɿ� �ش��ϴ� ��ȣ�� �Է��Ͻÿ� : ");
        scanf(" %d", &num);

        switch(num){
        case 1: //1�� ���� �� ��� �� �����ϰ� ä��
            printf("[A ���]\n");
            fillNumber(matrixA, row, col);
            printf("[B ���]\n");
            fillNumber(matrixB, row, col);
            break;
        case 2: //2�� ���� �� ��� A + B �� ��� ���
            printf("[A ��� + B ���]\n");
            addMatrix(matrixA, matrixB, row, col);
            break;
        case 3: //3�� ���� �� ��� A - B �� ��� ���
            printf("[A ��� - B ���]\n");
            subtractMatrix(matrixA, matrixB, row, col);
            break;
        case 4: //4�� ���� �� ��� A�� ��ġ��� T ���� �� ���
            transposeMatrix(matrixA, matrixT, col, row);
            break;
        case 5: //5�� ���� �� ��� A * B �� ��� ���
            printf("[A ��� * B ���]\n");
            multiplyMatrix(matrixA, matrixB, row, col);
            break;
        case 6: //6�� ���� �� ��� ���
            printf("[A ���]\n");
            printMatrix(matrixA, row, col);
            printf("[B ���]\n");
            printMatrix(matrixB, row, col);
            break;
        case 7: //7�� ���� �� ��� �����Ҵ� ���� �� �ý��� ����
            printf("�ý����� �����ϰڽ��ϴ�.\n");
            freeMatrix(matrixA, row, col);
            freeMatrix(matrixB, row, col);
            freeMatrix(matrixT, row, col);
            break;
        default:
            break;
        }
    }
    //while(num != 7); //7�� ���� �� �ݺ��� ����
    return 1;
}

//��� ���� �Լ�
int** makeMatrix(int row, int col){
    int **x = (int**)malloc(row*sizeof(*x)); //�迭 �ּ� ������ ���� ���� �Ҵ� 

    for(int i=0; i<row; i++){
        x[i]=(int*)malloc(col*sizeof(**x)); //�� ������ ���� ���� �Ҵ�
    }
    return x;
}

//��� ��� �Լ�
void printMatrix(int** matrix, int row, int col){
    for(int i=0; i<row; i++){ //�� �� �ݺ�
        for(int j=0; j<col; j++){ //�� �� �ݺ�
            printf("%d ",matrix[i][j]); //��� ���
        }
        printf("\n\n");
    }
}

//�����Ҵ� ���� �Լ�
int freeMatrix(int** matrix, int row, int col){
    for(int i=0; i<row; i++){ //�� �� �ݺ�
        free(matrix[i]); //�� �࿡ ���� �����Ҵ� �޸� ����
    }
    free(matrix); //��� ��ü�� ���� �����Ҵ� �޸� ����
    return 1;
}

//��� �� ä��� �Լ�
int fillNumber(int** matrix, int row, int col){
    for(int i=0; i<row; i++){ //�� �� �ݺ�
        for(int j=0; j<col; j++){ //�� �� �ݺ�
            matrix[i][j]=rand()%30; //��Ŀ� 0���� 30 ������ ���� �������� ������
        }
    }
    printMatrix(matrix, row, col);
    return 1;
}

//��� A+B
int addMatrix(int** matrixA, int** matrixB, int row, int col){
    int **matrixSum=makeMatrix(row,col); //matrixSum ����

    for(int i=0; i<row; i++){ //�� �� �ݺ�
        for(int j=0; j<col; j++){ //�� �� �ݺ�
            matrixSum[i][j]=matrixA[i][j]+matrixB[i][j]; //��� A�� B ���� �� matrixSum�� ����
        }
    }
    printMatrix(matrixSum, row, col); //matrixSum ���
    return 1;    
}

//��� A-B
int subtractMatrix(int** matrixA, int** matrixB, int row, int col){
    int **matrixSub=makeMatrix(row, col); //matrixSub ����

    for(int i=0; i<row; i++){ //�� �� �ݺ�
        for(int j=0; j<col; j++){ //�� �� �ݺ�
            matrixSub[i][j]=matrixA[i][j]-matrixB[i][j]; //��� A�� B �� �� matrixSub�� ����
        }
    }
    printMatrix(matrixSub, row, col); //matrixSub ���
    return 1;
}

//A�� ��ġ��� T
int transposeMatrix(int** matrixA, int** matrixT, int row, int col){
    printf("���� ���\n");
    printMatrix(matrixA, row, col); //A ��� ���
    printf("\n");

    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){ //�� �� �ݺ�
            matrixT[i][j]=matrixA[j][i]; //A ����� ��� ���� ��ü�� T ��Ŀ� ����
        }
    }
    printf("����� ���\n");
    printMatrix(matrixT, row, col);  //T ��� ���
    printf("\n");
    return 1;
}

//��� A �� B
int multiplyMatrix(int** matrixA, int** matrixB, int row, int col){
    int **matrixMul = makeMatrix(row, row);
    int mul=0;

    for(int i=0; i<row; i++){ //�� �� �ݺ�
        for(int j=0; j<row; j++){ //�� �� �ݺ�
            for(int k=0; k<col; k++){ //�߰��� ���Ǵ� ���� �ε����� ����� ���� ����
                mul+=(matrixA[i][k]*matrixB[k][j]); //mul�� ��� �� ��� ������ ����
            }
            matrixMul[i][j]=mul; //�� ����
            mul=0;
        }
    }
    printMatrix(matrixMul, row, row); //matrixMul ���
    return 1;
}