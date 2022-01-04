#include <stdio.h>
#include <windows.h>


//김종한
//덧셈
float math_plus(float a, float b){
    return a+b;
}

//뺄셈
float math_minus(float a, float b){
    return a-b; 
}

//곱셈
float math_multiplie(float a, float b){
    return a*b;
}

//나눗셈
float math_division(float a, float b){
    if(b==0){
        printf("0으로 나눌 수 없습니다.\n");
        return ;
    }
    return a/b;
}


//김현성
//나머지 연산
int math_rest(int a, int b){
    if(b==0){
        printf("0으로 나눌 수 없습니다.\n");
        return ;
    }
    return a%b;
}

//팩토리얼
int math_factorial(int n){
    if(n==1){
        return 1;
    }
    return math_multiplie(n, math_factorial(n-1));
}


//신준
//제곱
float math_power(float n, int a){
    float temp = 1;
    for(int i=0; i<a; i++){
        temp = temp*n;
    }
    return temp;
}

//제곱근
float math_root(float n){
    float x=n/2;
    for(int i=0; i<10; i++){
        x = (x + (n/x))/2;
    }
    return x;
}


//이연성
//두 점 사이 거리
float math_distance(float x1, float y1, float x2, float y2){
    return math_root(math_plus(math_power(x1 - x2, 2), math_power(y1 - y2, 2)));
}



//셋업
void setup(){
    //콘솔 지우기
    system( "cls" );

    //로고 그리기
    printf("   _____      _            _       _                    ___    ___  \n");
    printf("  / ____|    | |          | |     | |                  |__ \\  / _ \\ \n");
    printf(" | |     __ _| | ___ _   _| | __ _| |_ ___  _ __  __   __ ) || | | |\n");
    printf(" | |    / _` | |/ __| | | | |/ _` | __/ _ \\| '__| \\ \\ / // / | | | |\n");
    printf(" | |___| (_| | | (__| |_| | | (_| | || (_) | |     \\ V // /_ | |_| |\n");
    printf("  \\_____\\__,_|_|\\___|\\__,_|_|\\__,_|\\__\\___/|_|      \\_/|____(_)____/ \n\n");

    /*결과물
       _____      _            _       _                    ___    ___  
      / ____|    | |          | |     | |                  |__ \  / _ \ 
     | |     __ _| | ___ _   _| | __ _| |_ ___  _ __  __   __ ) || | | |
     | |    / _` | |/ __| | | | |/ _` | __/ _ \| '__| \ \ / // / | | | |
     | |___| (_| | | (__| |_| | | (_| | || (_) | |     \ V // /_ | |_| |
      \_____\__,_|_|\___|\__,_|_|\__,_|\__\___/|_|      \_/|____(_)___/ 
    */
}


int main(){
    //변수 선언
    float n1, n2, result;
    int input;


    //세팅
    setup();


    //계산할 값(첫번째) 받기
    printf("첫번째 값을 입력해주세요 : ");
    scanf("%f", &n1);


    while(1){
        printf("무슨 작업을 수행하실 건가요?\n");
        printf("0. 나가기\n");
        printf("1. 더하기\n");
        printf("2. 빼기\n");
        printf("3. 곱하기\n");
        printf("4. 나누기\n");
        printf("5. 나머지 연산\n");
        printf("6. 제곱\n");
        printf("7. 제곱근\n");
        printf("8. 팩토리얼\n");
        printf("9. 두 점 사이 거리\n");

        //모드 입력받기
        scanf("%d", &input);



        //연산
        switch (input){



        //나가기
        case 0:
            exit(0);
            break;



        //덧셈
        case 1:
            printf("더할 값을 입력해주세요 : ");
            scanf("%f", &n2);

            result = math_plus(n1, n2);
            printf("%g + %g = %g\n", n1, n2, result);

            break;



        //뺄셈
        case 2:
            printf("뺄 값을 입력해주세요 : ");
            scanf("%f", &n2);

            result = math_minus(n1, n2);
            printf("%g - %g = %g\n", n1, n2, result);

            break;



        //곱셈
        case 3:
            printf("곱할 값을 입력해주세요 : ");
            scanf("%f", &n2);

            result = math_multiplie(n1, n2);
            printf("%g X %g = %g\n", n1, n2, result);

            break;



        //나눗셈
        case 4:
            GETDIVISOR1: printf("나눌 값을 입력해주세요 : ");
            scanf("%f", &n2);

            if(n2==0){
                printf("0으로 나눌 수 없습니다.\n");
                goto GETDIVISOR1;
            }

            result = math_division(n1, n2);
            printf("%g / %g = %g\n", n1, n2, result);

            break;



        //나머지
        case 5:
            GETDIVISOR2: printf("나눌 값을 입력해주세요(정수형만 가능) : ");
            scanf("%f", &n2);

            if(n2==0){
                printf("0으로 나눌 수 없습니다.\n");
                goto GETDIVISOR2;
            }

            n1 = (int)n1;
            n2 = (int)n2;

            result = math_rest((int)n1, (int)n2);
            printf("%d / %d = %d ··· %d\n", (int)n1, (int)n2, (int)math_division(n1-result, n2), (int)result);

            break;



        //제곱
        case 6:
            printf("제곱할 진수를 입력해주세요(정수만 가능) : ");
            scanf("%f", &n2);

            n2 = (int)n2;

            result = math_power(n1, (int)n2);
            printf("%g^%d = %g\n", n1, (int)n2, result);

            break;



        //제곱근
        case 7:

            result = math_root(n1);
            printf("√%g = %g\n", n1, result);

            break;



        //팩토리얼
        case 8:

            result = math_factorial((int)n1);
            printf("%d! = %d\n", (int)n1, (int)result);

            break;



        //두 점 사이 거리
        case 9:

            setup();

            float x1, y1, x2, y2;

            printf("두 점 사이의 거리를 입력받습니다.\n");
            
            printf("첫 번째 점의 좌표를 입력하세요\n");
            printf("x1 y1 : ");
            scanf("%f %f", &x1, &y1);

            printf("두 번째 점의 좌표를 입력하세요\n");
            printf("x2 y2 : ");
            scanf("%f %f", &x2, &y2);

            result = math_distance(x1, y1, x2, y2);

            printf("(%g, %g), (%g, %g)\n", x1, y1, x2, y2);
            printf("거리 : %g", result);

            scanf("%c");
            break;



        //예외
        default:
            continue;
        }



        //계산 완료 후
        printf("계속 할까요?\n");
        printf("1. yes\n");
        printf("2. no\n");

        scanf("%d", &input);

        //2. 나갈래요
        //나가기
        if(input==2){
            break;
        }

        //1. 좀 더 할래요
        //초기화
        setup();
        n1 = result;
        printf("현재 값 : %g\n", n1);
    }
    //루프 끝나면 나가기
    exit(0);
}