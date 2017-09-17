#include <stdio.h>
#include<math.h>

int printPrimeNumber(int number);

int checkPrimeNumber(int number);
int checkArmstrongNumber(int number);

int checkPrime(int number);



int main()
{
	int call;//선택 숫자

	int n1,n2;//1번의 입력받는 두수
	int n;//입력받는 수
	int i,flag;//필요한 변수들
	
	printf("1.Display Prime Numbers Between Intervals Using Function.\n");
	printf("2.Check Prime or Armstrong Number Using User-defined Function.\n");
	printf("3.Check Whether a Number can be Expressed as Sum of Two Prime Numbers.\n");
	printf("위의 번호 중 하나를 누르시면 그에 맞는 답이 나옵니다.:");
	scanf("%d", &call);

	while((call<1)||(call>3))
	{
		printf("\n\n\n");
		printf("잘못된 번호를 누르셨습니다.\n");
		printf("1.Display Prime Numbers Between Intervals Using Function.\n");
		printf("2.Check Prime or Armstrong Number Using User-defined Function.\n");
		printf("3.Check Whether a Number can be Expressed as Sum of Two Prime Numbers.\n");
		printf("위의 번호 중 하나를 누르시면 그에 맞는 답이 나옵니다.:");
		scanf("%d", &call);
	}

	if(call==1)
	{
		printf("첫번째 정수를 입력하세요:");
		scanf("%d", &n1);
		printf("두번째 정수를 입력하세요:");
		scanf("%d", &n2);
		
		for(i=n1+1;i<n2;i++)
		{
			flag=printPrimeNumber(i);
			if(flag==1)
				printf("%d\n",i) ;    
		}
	}
	
	if(call==2)
	{
		printf("정수를 입력하세요:");
		scanf("%d", &n);
		checkPrimeNumber(n);
		checkArmstrongNumber(n);
	}
	
	if(call==3)
	{
		printf("정수를 입력하세요:");
		scanf("%d", &n);

		for(i=2; i<=n/2; ++i)
		{
			if(checkPrime(i)==1)
			{
				if(checkPrime(n-i)==1)
				{
					printf("%d=%d+%d\n",n,i,n-i);
					flag=1;
				}
			}
		}

		if(flag==0)
		{
			printf("%d 는 두개의 소수의 합으로 표현할 수 없습니다.",n);
		}

	}


	return 0;
}







int printPrimeNumber(int number)
{
  int j,flag=1;

 for(j=2;j<=number/2;++j)
	{
	 if(number%j==0)
	 {
	  flag=0;
	  break;
	 }
	}


  return flag;

}

int checkPrimeNumber(int number)
{
	int j,original,flag=1;
	
	original=number;
	
	for(j=2;j<=original/2;++j)
	{
		if(original%j==0)
		{
			flag=0;
			break;
		}
	}


	if(flag == 1)
	{
		printf("%d 는 소수 입니다.\n",number);
	}
	if(flag != 1)
	{
		printf("%d 는 소수가 아닙니다.\n",number);
	}

	return number;
}


int checkArmstrongNumber(int number)
{
	int originalNumber; // 입력한 넘버를 저장하는 변수
	float remainder;
	int result=0;
	int q=0; //자리수를 알려주는 변수다

	
	originalNumber=number;	
	while(originalNumber != 0)
	{
		/*check how many digts the originalNumber has*/
		originalNumber/=10;
		q++;
	}
	

	originalNumber=number;
	while(originalNumber != 0)
	{
		/* calculate the ArmstrongNumber of the originalNumber*/
		remainder = originalNumber%10;
		/*pow()를 쓰려고 하면 "둘 이상의 메서드 또는 속성이 이 인수 목록과 일치합니다." 라고 뜨는데 
		  이때 remainder를  float 형으로 고치면 데이터 손실 문제가 있다고 뜨지만 pow()함수를 쓸 수 있게 된다!*/
		
		result += pow(remainder,q); /*remainder의 n승을 의미한다구!*/
		originalNumber /=10;
	}

	originalNumber=number;
	
	printf("입력한 %d는 %d자리수 입니다.\n",number,q);
	
	if(result == number)
	{
		printf("%d 는 암스트롱 넘버 입니다.\n",number);
	}
	else
	{
		printf("%d 는 암스트롱 넘버가 아닙니다.\n",number);
	}
	
	return number;
}
	
int checkPrime(int number)
{
 /*생각을 해보자 정수를 입력해서 서수로써 정수의 합을 만들어야 된다
   10일때 2+8 안되지 3+7은 되지*/
  int j,flag=1;

 for(j=2;j<=number/2;++j)
	{
	 if(number%j==0)
	 {
	  flag=0;
	  break;
	 }
	}

  return flag;

 
}