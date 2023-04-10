#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 함수 선언
int** makeMatrix(int row, int col);
int fillNumber(int** matrix, int row, int col);
int addMatrix(int** matrixA, int** matrixB, int row, int col);
int subtractMatrix(int** matrixA, int** matrixB, int row, int col);
int transposeMatrix(int** matrixA, int** matrixT, int row, int col);
int multiplyMatrix(int** matrixA, int** matrixB, int row, int col);
void printMatrix(int** matrix, int row, int col);
int freeMatrix(int** matrix, int row, int col);

int main(){
    int row, col; //행과 열 선언
    int num; //입력받을 숫자 선언
    srand(time(NULL)); //랜덤함수 초기화
    printf("[----- [손지연] [2020039104] -----]\n\n");

    printf("행과 열의 수를 입력하시오 : ");
    scanf("%d %d", &row, &col); //행과 열 입력받기

    //행렬 생성
    int **matrixA = makeMatrix(row, col);
    int **matrixB = makeMatrix(row, col);
    int **matrixT = makeMatrix(row, col);

    printf("\n행렬 생성 완료\n\n");

    while(num!=7){
        printf("************************************************\n");
        printf("1. 행렬 값 랜덤하게 채우기\n");
        printf("2. 행렬 덧셈\n");
        printf("3. 행렬 뺄셈\n");
        printf("4. 행렬 전치\n");
        printf("5. 행렬 곱셈\n");
        printf("6. 행렬 출력\n");
        printf("7. 종료\n");
        printf("************************************************\n\n");

        printf("원하는 기능에 해당하는 번호를 입력하시오 : ");
        scanf(" %d", &num);

        switch(num){
        case 1: //1번 누를 시 행렬 값 랜덤하게 채움
            printf("[A 행렬]\n");
            fillNumber(matrixA, row, col);
            printf("[B 행렬]\n");
            fillNumber(matrixB, row, col);
            break;
        case 2: //2번 누를 시 행렬 A + B 후 결과 출력
            printf("[A 행렬 + B 행렬]\n");
            addMatrix(matrixA, matrixB, row, col);
            break;
        case 3: //3번 누를 시 행렬 A - B 후 결과 출력
            printf("[A 행렬 - B 행렬]\n");
            subtractMatrix(matrixA, matrixB, row, col);
            break;
        case 4: //4번 누를 시 행렬 A의 전치행렬 T 생성 후 출력
            transposeMatrix(matrixA, matrixT, col, row);
            break;
        case 5: //5번 누를 시 행렬 A * B 후 결과 출력
            printf("[A 행렬 * B 행렬]\n");
            multiplyMatrix(matrixA, matrixB, row, col);
            break;
        case 6: //6번 누를 시 행렬 출력
            printf("[A 행렬]\n");
            printMatrix(matrixA, row, col);
            printf("[B 행렬]\n");
            printMatrix(matrixB, row, col);
            break;
        case 7: //7번 누를 시 행렬 동적할당 해제 후 시스템 종료
            printf("시스템을 종료하겠습니다.\n");
            freeMatrix(matrixA, row, col);
            freeMatrix(matrixB, row, col);
            freeMatrix(matrixT, row, col);
            break;
        default:
            break;
        }
    }
    //while(num != 7); //7번 누를 시 반복문 종료
    return 1;
}

//행렬 생성 함수
int** makeMatrix(int row, int col){
    int **x = (int**)malloc(row*sizeof(*x)); //배열 주소 저장할 공간 동적 할당 

    for(int i=0; i<row; i++){
        x[i]=(int*)malloc(col*sizeof(**x)); //값 저장할 공간 동적 할당
    }
    return x;
}

//행렬 출력 함수
void printMatrix(int** matrix, int row, int col){
    for(int i=0; i<row; i++){ //행 번 반복
        for(int j=0; j<col; j++){ //열 번 반복
            printf("%d ",matrix[i][j]); //행렬 출력
        }
        printf("\n\n");
    }
}

//동적할당 해제 함수
int freeMatrix(int** matrix, int row, int col){
    for(int i=0; i<row; i++){ //행 번 반복
        free(matrix[i]); //각 행에 대한 동적할당 메모리 해제
    }
    free(matrix); //행렬 전체에 대한 동적할당 메모리 해제
    return 1;
}

//행렬 값 채우는 함수
int fillNumber(int** matrix, int row, int col){
    for(int i=0; i<row; i++){ //행 번 반복
        for(int j=0; j<col; j++){ //열 번 반복
            matrix[i][j]=rand()%30; //행렬에 0에서 30 사이의 값을 랜덤으로 지정함
        }
    }
    printMatrix(matrix, row, col);
    return 1;
}

//행렬 A+B
int addMatrix(int** matrixA, int** matrixB, int row, int col){
    int **matrixSum=makeMatrix(row,col); //matrixSum 생성

    for(int i=0; i<row; i++){ //행 번 반복
        for(int j=0; j<col; j++){ //열 번 반복
            matrixSum[i][j]=matrixA[i][j]+matrixB[i][j]; //행렬 A와 B 더한 값 matrixSum에 저장
        }
    }
    printMatrix(matrixSum, row, col); //matrixSum 출력
    return 1;    
}

//행렬 A-B
int subtractMatrix(int** matrixA, int** matrixB, int row, int col){
    int **matrixSub=makeMatrix(row, col); //matrixSub 생성

    for(int i=0; i<row; i++){ //행 번 반복
        for(int j=0; j<col; j++){ //열 번 반복
            matrixSub[i][j]=matrixA[i][j]-matrixB[i][j]; //행렬 A와 B 뺀 값 matrixSub에 저장
        }
    }
    printMatrix(matrixSub, row, col); //matrixSub 출력
    return 1;
}

//A의 전치행렬 T
int transposeMatrix(int** matrixA, int** matrixT, int row, int col){
    printf("원래 행렬\n");
    printMatrix(matrixA, row, col); //A 행렬 출력
    printf("\n");

    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){ //열 번 반복
            matrixT[i][j]=matrixA[j][i]; //A 행렬의 행과 열을 교체해 T 행렬에 대입
        }
    }
    printf("변경된 행렬\n");
    printMatrix(matrixT, row, col);  //T 행렬 출력
    printf("\n");
    return 1;
}

//행렬 A × B
int multiplyMatrix(int** matrixA, int** matrixB, int row, int col){
    int **matrixMul = makeMatrix(row, row);
    int mul=0;

    for(int i=0; i<row; i++){ //행 번 반복
        for(int j=0; j<row; j++){ //행 번 반복
            for(int k=0; k<col; k++){ //중간에 사용되는 공통 인덱스로 사용해 곱셈 수행
                mul+=(matrixA[i][k]*matrixB[k][j]); //mul에 행렬 곱 결과 누적해 더함
            }
            matrixMul[i][j]=mul; //값 대입
            mul=0;
        }
    }
    printMatrix(matrixMul, row, row); //matrixMul 출력
    return 1;
}