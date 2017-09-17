#include <stdio.h>
#include<math.h>

int printPrimeNumber(int number);

int checkPrimeNumber(int number);
int checkArmstrongNumber(int number);

int checkPrime(int number);



int main()
{
	int call;//���� ����

	int n1,n2;//1���� �Է¹޴� �μ�
	int n;//�Է¹޴� ��
	int i,flag;//�ʿ��� ������
	
	printf("1.Display Prime Numbers Between Intervals Using Function.\n");
	printf("2.Check Prime or Armstrong Number Using User-defined Function.\n");
	printf("3.Check Whether a Number can be Expressed as Sum of Two Prime Numbers.\n");
	printf("���� ��ȣ �� �ϳ��� �����ø� �׿� �´� ���� ���ɴϴ�.:");
	scanf("%d", &call);

	while((call<1)||(call>3))
	{
		printf("\n\n\n");
		printf("�߸��� ��ȣ�� �����̽��ϴ�.\n");
		printf("1.Display Prime Numbers Between Intervals Using Function.\n");
		printf("2.Check Prime or Armstrong Number Using User-defined Function.\n");
		printf("3.Check Whether a Number can be Expressed as Sum of Two Prime Numbers.\n");
		printf("���� ��ȣ �� �ϳ��� �����ø� �׿� �´� ���� ���ɴϴ�.:");
		scanf("%d", &call);
	}

	if(call==1)
	{
		printf("ù��° ������ �Է��ϼ���:");
		scanf("%d", &n1);
		printf("�ι�° ������ �Է��ϼ���:");
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
		printf("������ �Է��ϼ���:");
		scanf("%d", &n);
		checkPrimeNumber(n);
		checkArmstrongNumber(n);
	}
	
	if(call==3)
	{
		printf("������ �Է��ϼ���:");
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
			printf("%d �� �ΰ��� �Ҽ��� ������ ǥ���� �� �����ϴ�.",n);
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
		printf("%d �� �Ҽ� �Դϴ�.\n",number);
	}
	if(flag != 1)
	{
		printf("%d �� �Ҽ��� �ƴմϴ�.\n",number);
	}

	return number;
}


int checkArmstrongNumber(int number)
{
	int originalNumber; // �Է��� �ѹ��� �����ϴ� ����
	float remainder;
	int result=0;
	int q=0; //�ڸ����� �˷��ִ� ������

	
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
		/*pow()�� ������ �ϸ� "�� �̻��� �޼��� �Ǵ� �Ӽ��� �� �μ� ��ϰ� ��ġ�մϴ�." ��� �ߴµ� 
		  �̶� remainder��  float ������ ��ġ�� ������ �ս� ������ �ִٰ� ������ pow()�Լ��� �� �� �ְ� �ȴ�!*/
		
		result += pow(remainder,q); /*remainder�� n���� �ǹ��Ѵٱ�!*/
		originalNumber /=10;
	}

	originalNumber=number;
	
	printf("�Է��� %d�� %d�ڸ��� �Դϴ�.\n",number,q);
	
	if(result == number)
	{
		printf("%d �� �Ͻ�Ʈ�� �ѹ� �Դϴ�.\n",number);
	}
	else
	{
		printf("%d �� �Ͻ�Ʈ�� �ѹ��� �ƴմϴ�.\n",number);
	}
	
	return number;
}
	
int checkPrime(int number)
{
 /*������ �غ��� ������ �Է��ؼ� �����ν� ������ ���� ������ �ȴ�
   10�϶� 2+8 �ȵ��� 3+7�� ����*/
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