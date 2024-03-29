#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

int Centered(int *arr, int size)
{
    if(size % 2 == 0)
    {
        //No middle element
        return 0;
    }
    else if(size == 0)
    {
        return 0;
    }
    else if(size == 1)
    {
        return 1;
    }
    else
    {
         int mid = arr[size/2],flag = 0;
         for(int i = 0; i < size; i++)
         {
            if(i == size/2)
            {
                continue;
            }
            if(mid >= arr[i])
            {
                flag = 1;
                break;
            }
         }

         if(flag == 1)
         {
            return 0;
         }
         else 
         {
            return 1;
         }
    }
}

int ARRAYSIZE(char *arr)
{
    int i = 0, size = 0;
    while(arr[i] != '\0')
    {
        size++;
    }
    return size;
}

char* f(char* a, int start, int len, int size)
{
    if (len > size || start < 0 || start + len > size)
    {
        return NULL;
    }

    char *result = (char*)malloc((len + 1) * sizeof(char));
    if (result == NULL)
    {
        return NULL; // Memory allocation failed
    }

    int dynamic_index = 0;
    for (int i = start; i < start + len; i++)
    {
        result[dynamic_index] = a[i];
        dynamic_index++;
    }
    result[dynamic_index] = '\0'; // Null-terminate the result string
    return result;
}

int EvvOdd(int *arr, int size)
{
    int X = 0, Y = 0;

    if(size == 0)
    {
        return 0;
    }
    else if(size == 1)
    {
        if(arr[0]%2 == 0)
        {
            Y = arr[0];
            return X-Y;
        }
        else
        {
            X = arr[0];
            return X-Y;
        }
    }
    else
    {
        for(int i = 0; i < size; i++)
        {
            if(arr[i]%2 == 0)
            {
                Y += arr[i];
            }
            else
            {
                X += arr[i];
            }
        }
    }
    return X-Y;
}

void printArray(char *arr, int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("%c ",arr[i]);
    }
    printf("\n");
}

int reverse(int num)
{
    int res = 0;
    int negative = 0;
    if(num/10 == 0)
    {
        return num;
    }
    else
    {
        if(num < 0)
        {
            num = num * -1;
            negative = 1;
        }
        res = 0;
        while(num > 0)
        {
            int x = num%10;

            res*=10;
            res = res + x;

            num = num/10;
        }
    }

    if(negative == 1)
    {
        res = res * -1;
    }
    return res;
}

int match(int *arr, int size1, int* arr2, int size2)
{
    int match = 0;
        for(int i = 0; i < size1; i++)
        {
            for(int j = 0; j < size2; j++)
            {
                if(arr[i] == arr2[j])
                {
                    match++;
                    break;
                }
            }
        }
    return match;
}

int* COMMON(int *arr, int size1, int* arr2, int size2)
{
    int matching = match(arr,size1,arr2,size2);
    if(matching == 0)
    {
        return NULL;
    }
    else if(arr2 == NULL || arr == NULL)
    {
        return NULL;
    }
    else
    {
        int *myResult = (int*)malloc(matching*sizeof(int));
        int dynamic = 0;
        for(int i = 0; i < size1; i++)
        {
            for(int j = 0; j < size2; j++)
            {
                if(arr[i] == arr2[j])
                {
                    myResult[dynamic] = arr[i];
                    dynamic++;
                    break;
                }
            }
        }
        return myResult;
    }
}

int POE(int *arr, int size)
{
    int POE_N = -1;
    for(int i = 1; i < size; i++)
    {
        int Left = 0;
        int Right = 0;
        for(int j = 0; j < i; j++)
        {
            Left += arr[j];
        }

        for(int j = i+1; j < size; j++)
        {
            Right += arr[j];
        }

        if(Left == Right)
        {
            POE_N = i;
            break;
        }
    }
    return POE_N;
}

int SecondLargest(int *arr, int size)
{
    if(size == 0)
    {
        return -1;
    }
    
    if(size == 1)
    {
        return -1;
    }

    int all_eql = 0;
    for(int i = 1; i < size; i++)
    {
        if(arr[i] != arr[i-1])
        {
            all_eql = 0;
            break;
        }
        all_eql = 1;
    }

    if(all_eql == 1)
    {
        return -1;
    }

    for(int i = 0; i < size; i++)
    {
        for(int j = i+1; j < size; j++)
        {
            if(arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    if(arr[size-2] == arr[size-1])
    {
        int i = size-2;
        while(arr[i] == arr[size-1])
        {
            i--;
        }
        return arr[i];
    }
    else
    {
        return arr[size-2];
    }   
}

int nextPerfectSquare(int n)
{
    int flagFound = 0;
    int perfect = 0;

    while(flagFound == 0)
    {
        n = n+1;

        for(int i = 1; i <= n/2; i++) // Changed the loop range and condition
        {
            if(i*i == n)
            {
                flagFound = 1;
                perfect = n;
                break;
            }
            else if(i*i > n)
            {
                break;
            }
        }
    }
    return perfect;
}

int upCount(int *arr, int len, int n)
{
    int upCount = 0, sum = 0, up = 0;
    for(int i = 0; i < len; i++)
    {
        sum += arr[i];
        if(sum >= n && up == 0)
        {
            up = 1;
            upCount++;
        }
        else if(sum < n && up == 1)
        {
            up = 0;
        }
    }
    return upCount;
}

int primeCount(int start,int end)
{
    if(start < 0)
    {
        start = 1;
    }

    int primeC = 0, isPrime = 1;
    for(int i = start; i <= end; i++)
    {
        if(i == 1)
        {
            continue;
        }

        isPrime = 1;
        for(int j = 2; j < i; j++)
        {
            if(i%j == 0)
            {
                isPrime = 0;
                break;
            }
        }
        if(isPrime == 1)
        {
            primeC++;
        }
    }
    return primeC;
}

int Madhav(int *arr, int size)
{
    int Madh = arr[0];
    int i = 1;
    int next = 2;
    int sum = 0;
    int valid = 1;
    while(i<size)
    {
        sum = 0;
        for(int j = i; j <= i+next-1; j++)
        {
            sum += arr[j];
        }

        if(sum != arr[0])
        {
            valid = 0;
            break;
        }

        i += next;
        next++;
    }
    return valid;
}

int inertial(int *arr, int size)
{
    int MaxValue = 0;
    int valid = 1;
    int OddCondition = 0;

    for(int i = 0; i < size; i++)
    {


        for(int j = i+1; j < size; j++)
        {
            if(arr[j]%2 != 0)
            {
                OddCondition++;
            }

            if(arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    if(arr[size-1]%2 != 0 || OddCondition == 0)
    {
        valid = 0;
        return valid;
    }
    else
    {
        MaxValue = arr[size-1];
    }

    int error = 0;
    for(int i = 0; i < size; i++)
    {
        if(arr[i]%2 != 0)
        {
            for(int j = 0; j < size; j++)
            {
                if(arr[j]%2 == 0 && arr[j] != MaxValue)
                {
                    if(arr[i] < arr[j])
                    {
                        valid = 0;
                        error = 1;
                        break;
                    }
                }
            }
        }
        if(error == 1)
        {
           break;
        }
    }
    return valid;
}

int countSquarePairs(int *arr, int size)
{
    int Res = 0;
    for(int i = 0; i < size; i++)
    {
        for(int j = i+1; j < size; j++)
        {
            if(arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    for(int i = 0; i < size; i++)
    {
        for(int j = i+1; j < size; j++)
        {
            int rt = (int)sqrt(arr[i]+arr[j]);
            if(rt*rt == arr[i]+arr[j] && arr[i]>0 && arr[j] > 0)
            {
                Res++;
            }
        }
    }
    return Res;
}

int isPrime(int n)
{
    int prime = 1;
    for(int i = 2; i < n; i++)
    {
        if(n%i == 0)
        {
            prime = 0;
            break;
        }
    }
    return prime;
}

int findPorcupineNumber(int n)
{
    int found = 0;
    n++;
    while(found == 0)
    {
        int p = isPrime(n);
        if(p == 1 && n%10 == 9)
        {
            int next = n+1;
            while(isPrime(next) != 1)
            {
                next++;
            }

            if(next%10 == 9)
            {
                found = 1;
            }
            else
            {
                n = next+1;
            }
        }
        n++;
    }

    return n-1;
}

int  isGuthrieSequence(int *a, int len)
{
    int result = 1;

    if(a[len-1] != 1)
    {
        result = 0;
        return result;
    }
    else
    {
    int nextTerm;
    for(int i = 0; i < len-1; i++)
    {     
        if(a[i]%2 == 0)
        {
            nextTerm = a[i]/2;
        }
        else
        {
            nextTerm = (a[i]*3)+1;
        }

        if(nextTerm != a[i+1])
        {
            result = 0;
            break;
        }
    }
    }
    return result;
}

int stantonMeasure(int *a, int len)
{
    int n = 0;
    for(int i = 0; i < len; i++)
    {
        if(a[i] == 1)
        {
            n++;
        }
    }

    int Occ = 0;
    for(int i = 0; i < len; i++)
    {
        if(a[i] == n)
        {
            Occ++;
        }
    }

    return Occ;
}

int sumFactor(int *a, int len)
{
    int Occ = 0, sum = 0;
    if(len == 0)
    {
        return 0;
    }
    else
    {
        for(int i = 0; i < len; i++)
        {
            sum += a[i];
        }

        for(int i = 0; i < len; i++)
        {
            if(sum == a[i])
            {
                Occ++;
            }
        }
    }

    return Occ;
}

int numberSize(int num)
{
    int len = 0;
    while (num != 0)
    {
        len++;
        num /= 10;
    }
    return len;
}

void tostring(char str[], int num)
{
    int i, rem, n;

    n = num;
    int len = numberSize(n);
    for (i = 0; i < len; i++)
    {
        rem = num % 10;
        num = num / 10;
        str[len - (i + 1)] = rem + '0';
    }
    str[len] = '\0';
}

int repsEqual(int *a, int len, int n)
{
    int NumberLength = numberSize(n);
    if(len < NumberLength)
    {
        return 0;
    }

    int F = 0;
    int CountNonLeadingZeros = 0;

    for(int i = 0; i < len; i++)
    {
        if(a[i] == 0 && F == 0)
        {
            continue;
        }
        else if(a[i] != 0 && F == 0)
        {
            F = 1;
            CountNonLeadingZeros++;
        }
        else
        {
            CountNonLeadingZeros++;
        }
    }

    if(NumberLength != CountNonLeadingZeros)
    {
        return 0;
    }

    char *STR = (char *)malloc((NumberLength + 1) * sizeof(char)); // Added +1 for null terminator
    int dynamicIndex = 0;
    int RET = 1;
    tostring(STR, n);

    int FirstNumber = 0;
    for (int i = 0; i < len; i++)
    {
        if (FirstNumber == 0 && a[i] == 0)
        {
            continue;
        }
        else if (FirstNumber == 0 && a[i] != 0)
        {
            FirstNumber = 1;
            if (a[i] == STR[dynamicIndex] - '0')
            {
                dynamicIndex++;
            }
            else
            {
                RET = 0;
                break;
            }
        }
        else
        {
            if (a[i] == STR[dynamicIndex])
            {
                dynamicIndex++;
            }
            else
            {
                break;
            }
        }
    }
    free(STR); // Free the dynamically allocated memory
    return RET;
}

int isCentered5(int a[], int len) {
    for (int i = 0; i < len; i++) {
        int sum = 0;
        for (int j = i; j < len; j++) {
            sum += a[j];
            if (sum == 15) {
                int leftCount = i;
                int rightCount = len - j - 1;
                if (leftCount == rightCount) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

int henry(int x, int y)
{
    int PerfectTwo = 0;

    int FirstPerfect = 0;
    int SecondPerfect = 0;

    int CurrentPerfect = 1;

    int NextNumber = 6;
    while(PerfectTwo == 0)
    {
        int sum = 0;
        for(int i = 1; i < NextNumber; i++)
        {
            if(NextNumber%i == 0)
            {
                sum += i;
            }
        }

        if(sum == NextNumber && FirstPerfect == 0 && CurrentPerfect == x)
        {
            FirstPerfect = NextNumber;
            CurrentPerfect++;
        }
        else if(sum == NextNumber && SecondPerfect == 0 && CurrentPerfect == y)
        {
            SecondPerfect = NextNumber;
            PerfectTwo = 1;
        }
        else if(sum == NextNumber && CurrentPerfect != x && CurrentPerfect != y)
        {
            CurrentPerfect++;
        }
        NextNumber++;
    }

    return FirstPerfect+SecondPerfect;
}

int isDivisible(int a[ ], int len, int divisor)
{
    int isDiv = 0;
    for(int i = 0; i < len; i++)
    {
        if(a[i]%divisor == 0)
        {
            isDiv++;
        }
    }

    if(isDiv == len)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isNUnique(int a[ ], int len, int n)
{
    int Found = 0;
    for(int i = 0; i < len; i++)
    {
        for(int j = i+1; j < len; j++)
        {
            if(a[i] + a[j] == n)
            {
                Found++;
            }
        }
    }
    
    if(Found == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isSquare(int n)
{
    for(int i = 0; i <= n/2; i++)
    {
        if(i*i == n)
        {
            return 1;
        }
    }
    return 0;
}

int myPow(int n, int p)
{
    int power = 1;
    for(int i = 0; i < p; i++)
    {
        power *= n;
    }
    return power;
}

int isLegalNumber(int a[ ], int len, int base)
{
    int legal = 1;
        for(int i = 0; i < len; i++)
    {
        if(a[i] > base)
        {
            legal = 0;
            break;
        }
    }

    return legal;
}

int converteToBase10(int a[ ], int len, int base)
{
    int leg = isLegalNumber(a,len,base);

    if(leg == 0)
    {
        return 0;
    }

    int power = len-1;
    int convertedNumber = 0;

    for(int i = 0; i < len; i++)
    {
        convertedNumber += ((a[i])*(myPow(base,power)));
        power--;
    }

    return convertedNumber;
}

int arrayHasNoZeros(int *arr, int size)
{
    for(int i = 0; i < size; i++)
    {
        if(arr[i] == 0)
        {
            return 0;
        }
    }
    return 1;
}

bool allDigitsSeen(bool digits[])
{
    for (int i = 0; i < 10; i++)
    {
        if (!digits[i])
        {
            return false;
        }
    }
    return true;
}

int computeDepth(int n)
{
    if (n <= 0)
    {
        return -1; // Invalid input
    }

    bool digits[10] = {false};
    int i = 1;
    while (true)
    {
        int cont = n * i;
        while (cont > 0)
        {
            int digit = cont % 10;
            digits[digit] = true;
            cont /= 10;
        }
        if (allDigitsSeen(digits))
        {
            return i;
        }
        i++;
    }
}

int matches(int a[], int len, int p[]) {
    int P_len = p[0];
    int P_abs_sum = 0;
    int j = 0;
    int error = 0;

    for (int i = 1; i <= P_len; i++) {
        P_abs_sum += abs(p[i]);
        int isNegative;
        if (p[i] < 0) {
            isNegative = 1;
        } else {
            isNegative = 0;
        }

        for (int k = 0; k < abs(p[i]); k++) {
            if (j >= len) {
                error = 1;
                break;
            }

            if ((isNegative == 1 && a[j] < 0) || (isNegative == 0 && a[j] >= 0)) {
                j++;
            } else {
                error = 1;
                break;
            }
        }
        if (error == 1) {
            break;
        }
    }

    if (error == 0 && P_abs_sum == len) {
        return 1;
    } else {
        return 0;
    }
}

int isStacked(int n)
{
    int stacked = 0;
    int i = 1;
    while (stacked < n)
    {
        stacked += i;
        i++;
    }

    if (stacked == n)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isSumSafe(int a[ ], int len)
{
    int sum = 0;
    for(int i = 0; i < len; i++)
    {
        sum += a[i];
    }

    for(int i = 0; i < len; i++)
    {
        if(a[i] == sum)
        {
            return 0;
        }
    }

    return 1;
}

int isIsolated(long n)
{
    if(n > 2097151)
    {
        return 0;
    }

    long square = n*n;
    long cube = n*n*n;
    int cube_digits = numberSize(cube);
    int square_digits = numberSize(square);

    for(int i = 0; i < cube_digits; i++)
    {
        int c_digit = cube%10;
        cube = cube/10;
        int s_digit;
        long squares = square;
        for(int j = 0; j < square_digits; j++)
        {
            s_digit = squares%10;
            if(c_digit == s_digit)
            {
                return 0;
            }
            squares = squares/10;
        }
    }
    return 1;
}

int isVanilla(int a[ ], int len)
{
    if(len == 0)
    {
        return 0;
    }

    int x = ((a[0])%10);
    
    for(int i = 0; i < len; i++)
    {
        int number = a[i];
        int digit;
        while(number > 0)
        {
            digit = number%10;
            if(digit != x)
            {
                return 0;
            }
            number = number/10;
        }
    }
    return 1;
}

int SearchArray(int *arr, int len, int element)
{
    for(int i = 0; i < len; i++)
    {
        if(element == arr[i])
        {
            return 1;
        }
    }
    return 0;
}

int isTrivalent(int a[ ], int len)
{
    int Triv_Arr[3];
    int TrivCounter = 0;

    for(int i = 0; i < len; i++)
    {
        if(SearchArray(Triv_Arr,3,a[i]) == 0 && TrivCounter < 3)
        {
            Triv_Arr[TrivCounter] = a[i];
            TrivCounter++;
        }
        else if(SearchArray(Triv_Arr,3,a[i]) == 0 && TrivCounter == 3)
        {
            return 0;
        }
    }

    if(TrivCounter != 3)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int countRepresentations(int numRupees)
{
    int count = 0;
        for (int rupee20=0; rupee20<=numRupees; rupee20+=20)
            for (int rupee10=0; rupee10<=numRupees; rupee10+=10)
                for (int rupee5=0; rupee5<=numRupees; rupee5+=5)
                    for (int rupee2=0; rupee2<=numRupees; rupee2+=2)
                        for (int rupee1=0; rupee1<=numRupees; rupee1++)
                        {
                            if (rupee20+rupee10+rupee5+rupee2+rupee1 == numRupees) 
                            count++;
                        }
    return count;
}

int isSequentiallyBounded(int a[], int len)
{
    if (len == 0)
    {
        return 1; // Empty array is considered sequentially-bounded
    }

    for (int i = 0; i < len - 1; i++)
    {
        if (a[i] > a[i + 1])
        {
            return 0; // Array is not in ascending order
        }
        
        if(a[i] < 0)
        {
            return 0; //Negative value
        }

        int counter = 1; // Start counter at 1, since we've already seen one occurrence
        for (int j = 0; j < len; j++)
        {
            if (a[j] == a[i])
            {
                counter++;
                if (counter > a[i])
                {
                    return 0; // Value occurs more than its index allows
                }
            }
        }
    }

    return 1; // Array is sequentially-bounded
}

void swap(int *x,int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void SortArray_ASC(int *arr, int len)
{
    for(int i = 0; i < len; i++)
    {
        for(int j = i+1; j < len; j++)
        {
            if(arr[i] > arr[j])
            {
                swap(&arr[i],&arr[j]);
            }
        }
    }
}

int isMinMaxDisjoint(int a[], int len)
{
    if (len < 2)
    {
        return 0; // Array must have at least 2 elements
    }

    int Min = a[0], Max = a[0], indexMax = 0;

    for (int i = 1; i < len; i++)
    {
        if (a[i] < Min)
        {
            Min = a[i];
        }

        if (a[i] > Max)
        {
            Max = a[i];
            indexMax = i;
        }
    }

    if (indexMax == 0 && a[1] == Min)
    {
        return 0; // Special case when max is at index 0
    }

    if (indexMax == len - 1 && a[len - 2] == Min)
    {
        return 0; // Special case when max is at last index
    }

    if (indexMax > 0 && indexMax < len - 1 && (a[indexMax - 1] == Min || a[indexMax + 1] == Min))
    {
        return 0; // Min and Max are adjacent
    }

    int countMin = 0, countMax = 0;
    for (int i = 0; i < len; i++)
    {
        if (a[i] == Min)
        {
            countMin++;
            if (countMin > 1)
            {
                return 0; // Min occurs more than once
            }
        }
        else if (a[i] == Max)
        {
            countMax++;
            if (countMax > 1)
            {
                return 0; // Max occurs more than once
            }
        }
    }

    if (Min == Max)
    {
        return 0; // Min and Max are equal
    }

    return 1; // Array is minmax-disjoint
}

int smallest(int n)
{
    int found = 0;
    int currentNumber = 1;
    int success = 0;

    while(found == 0)
    {
        int number = currentNumber;
        success = 0;
        for(int i = 1; i <= n; i++)
        {
            number = currentNumber*i;
            while(number>0)
            {
                int digit = number%10;
                if(digit == 2)
                {
                    success++;
                    break;
                }
                number = number/10;
            }
        }

        if(success == n)
        {
            found = 1;
        }

        currentNumber++;
    }

    return currentNumber-1;
}

int numberOfClusters(int *arr, int size)
{
    int cluster = 1;
    for(int i = 1; i < size; i++)
    {
        if(arr[i] != arr[i-1])
        {
            cluster++;
        }
        else
        {
            continue;
        }
    }
    return cluster;
}

void printArr(int *arr, int size)
{
    if(size == 0 || arr == NULL)
    {
        printf("NULL");
    }
    else
    {
    for(int i = 0; i < size; i++)
    {
        printf("%d ",arr[i]);
    }
    }
    printf("\n");
}

int *clusterCompression(int a[ ], int len)
{
    int  Result_Size = numberOfClusters(a,len);
    int* Result = (int*)malloc(Result_Size*sizeof(int));
    int dynamic_index = 0;

    for(int i = 1; i <= len; i++)
    {
        if(a[i] != a[i-1])
        {
            Result[dynamic_index] = a[i-1];
            dynamic_index++;
        }
    }
    return Result;
}

int isRailroadTie(int a[], int len)
{
    int railRoad = 1;
    int zeroCount = 0;
    int nonZeroNeighbours = 0;

    if(len == 1)
    {
        railRoad = 0;
        return railRoad;
    }
    else
    {}

    for(int i = 0; i < len; i++)
    {
        nonZeroNeighbours = 0;
        if(a[i] == 0)
        {
            zeroCount++;
            if(i == 0)
            {
                railRoad = 0;
                break;
            }
            else if(i == len-1)
            {
                railRoad = 0;
                break;
            }
            else
            {
                if(a[i-1] == 0 || a[i+1] == 0)
                {
                    railRoad = 0;
                    break;
                }
            }
        }
        else
        {
            if(i == 0)
            {
                if(a[i+1] == 0)
                {
                railRoad = 0;
                break;
                }
                else
                {}
            }
            else if(i == len-1)
            {
                if(a[i-1] == 0)
                {
                railRoad = 0;
                break;
                }
                else
                {}
            }
            else
            {
                if(a[i-1] != 0)
                {
                    nonZeroNeighbours++;
                }
                else
                {}
                
                if(a[i+1] != 0)
                {
                    nonZeroNeighbours++;
                }
                else
                {}

                if(nonZeroNeighbours != 1)
                {
                    railRoad = 0;
                    break;
                }
            }
        }
    }
    return railRoad;
}

int ToAnyBase(int number, int base) {
    int convertedNumber = 0;
    int multiplier = 1;

    while (number != 0) {
        int remainder = number % base;
        convertedNumber += remainder * multiplier;
        multiplier *= 10;
        number /= base;
    }
    return convertedNumber;
}

int fullnessQuotient(int n)
{
    int results = 0;
    int error = 0;
    if(n < 0)
    {
        results = -1;
        return results;
    }
    for(int i = 2; i <= 9; i++)
    {
        error = 0;
        int myNumber = ToAnyBase(n,i);
        while(myNumber > 0)
        {
            int digit = myNumber%10;
            if(digit == 0)
            {
                error = 1;
                break;
            }
            myNumber = myNumber/10;
        }
        if(error == 0)
        {
            results++;
        }
    }
    return results;
}

int isPacked(int a[], int len) {
    int index_counter = 1;
    
    for (int i = 0; i < len; i += index_counter) {
        int x = 0;
        for (int j = i; j < len && a[i] == a[j]; j++) {
            x++;
        }
        if (x != a[i] || (i > 0 && a[i] == a[i - 1])) {
            return 0;
        }
        index_counter = x;
    }
    
    return 1;
}

int isOddHeavy(int a[ ], int len)
{
    int oddValues = 0;
    for(int i = 0; i < len; i++)
    {
        if(a[i]%2 != 0)
        {
            oddValues++;
            for(int j = 0; j < len; j++)
            {
                if(j == i)
                {
                    continue;
                }
                else
                {
                    if(a[i] < a[j] && a[j]%2 == 0)
                    {
                        return 0;
                    }
                    else
                    {}
                }
            }
        }
        else
        {}
    }

    if(oddValues == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int getExponent(int n, int p)
{
    if(p <= 1)
    {
        return -1;
    }
    else
    {}

    int found = 0;
    int Exponent = 0;
    while(found == 0)
    {
        if(n%((int)pow(p,Exponent)) == 0)
        {
            Exponent++;
        }
        else
        {
            found = 1;
        }
    }
    return Exponent-1;
}

int is121Array(int a[], int len) 
{
    int twoCount = 0;
    int onesDone = 0;
    if(a[0] != a[len-1] || a[0] != 1)
    {
        return 0;
    }
    else
    {
        
        for(int i = 0; i <= len/2; i++)
        {
            if(a[i] == a[len-i-1])
            {
                if(a[i] == 2)
                {
                twoCount++;
                onesDone = 1;
                }

                if(a[i] == 1 && onesDone == 1)
                {
                    return 0;
                }
            }
            else
            {
                return 0;
            }
        }
    }

    if(twoCount > 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int countOnesInBinary(int BIN,int *MaxIndex)
{
    int count = 0;
    int index = 0;
    while(BIN > 0)
    {
        int BIT = BIN%10;
        if(BIT == 1)
        {
            count++;
        }
        BIN = BIN/10;
        index++;
    }
    *MaxIndex = index;
    return count;
}

int * filterArray(int a[ ], int len, int n, int *result_size)
{
    int binaryNumber = ToAnyBase(n,2);
    int MaxIndex;
    int Result_Size = countOnesInBinary(binaryNumber,&MaxIndex);
    *result_size = Result_Size;
    int *Result = (int*)malloc(Result_Size*(sizeof(int)));
    int dynamic_index = 0;
    if(Result_Size == 0 || MaxIndex > len)
    {
        free(Result);
        return NULL;
    }
    else
    {
        for(int i = 0; i < len; i++)
        {
            int bit = binaryNumber%10;
            if(bit == 1)
            {
                Result[dynamic_index] = a[i];
                dynamic_index++;
            }
            binaryNumber = binaryNumber/10;
        }
    }
    return Result;
}

int largestAdjacentSum(int a[ ], int len)
{
    int sum = 0;
    for(int i = 1; i < len; i++)
    {
        if(a[i-1] + a[i] > sum)
        sum = a[i] + a[i-1];
    }
    return sum;
}

int checkConcatenatedSum(int n, int catlen)
{
    int Number = n;
    int sum = 0;
    int digit;
    while(Number > 0)
    {
        digit = Number%10;

        if(catlen > 1)
        {
        int number = 0;
        for(int i = 0; i < catlen; i++)
        {
            number = number*10;
            number += digit;
        }
        digit = number;
        }
        sum += digit;
        Number = Number/10;
    }

    if(sum == n)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isSequencedArray(int a[ ], int len, int m, int n)
{
    int AvNumbers = (n-m)+1;
    int CheckElements = 1;
    for(int i = 1; i < len; i++)
    {
        if(a[i] < a[i-1])
        {
            return 0;
        }
        else if(a[i] == a[i-1] && a[i] <= n && a[i] >= m)
        {
            continue;
        }
        else if(a[i] - a[i-1] == 1 && a[i] <= n && a[i] >= m)
        {
            CheckElements++;
        }
        else
        {
            return 0;
        }
    }

    if(CheckElements == AvNumbers)
    {
        return 1;
    }
    else 
    {
        return 0;
    }
}

 int largestPrimeFactor(int n)
 {
    int primeFactor = 0;
    if( n <= 1)
    {
        return 0;
    }
    else
    {
        for(int i = 2; i < n; i++)
        {
            if(isPrime(i) == 1 && i > primeFactor && n%i == 0)
            {
                primeFactor = i;
            }
        }
    }
    return primeFactor;
 }

int primeNumbersExist(int n)
{
    int count = 0;
    for(int i = 2; i <= n; i++)
    {
        if(isPrime(i) == 1)
        {
            count++;
        }
    }
    return count;
}

int *encodeNumber(int n, int* resultSize)
{
    if(n <= 1)
    {
        return NULL;
    }

    int primesSize = primeNumbersExist(n);
    int* primes = (int*)malloc(primesSize*sizeof(int));
    int primesIndex = 0;

    for(int i = 2; i <= n; i++)
    {
        if(isPrime(i) == 1)
        {
            primes[primesIndex] = i;
            primesIndex++;
        }
    }

    primesIndex = 0;
    //Figure out the size of the result array
    int myNumber = n;
    int Result_Size = 0;
    while(myNumber != 1)
    {
        if(myNumber%primes[primesIndex] == 0)
        {
            Result_Size++;
            myNumber = myNumber/primes[primesIndex];
        }
        else
        {
            primesIndex++;
        }
    }

    primesIndex = 0;
    myNumber = n;
    //Create the Result Array
    int *Result = (int*)malloc(Result_Size*sizeof(int));
    int  Result_Index = 0;
    while(myNumber != 1)
    {
        if(myNumber%primes[primesIndex] == 0)
        {
            Result[Result_Index] = primes[primesIndex];
            myNumber = myNumber/primes[primesIndex];
            Result_Index++;
        }
        else
        {
            primesIndex++;
        }
    }

    free(primes);

    *resultSize = Result_Size;
    return Result;
}

static int matchPattern(int a[], int len, int pattern[], int patternLen)
{
    int i=0; // index into a
    int k=0; // index into pattern
    int matches = 0; // how many times current pattern character has been matched so far
        for (i=0; i<len; i++) 
        {
            if (a[i] == pattern[k])
                matches++; // current pattern character was matched
            else if (matches == 0 || k == patternLen-1)
                return 0; // if pattern[k] was never matched (matches==0) or at end of pattern (k==patternLen-1)
            else
            {
                k++;
                if(pattern[k] != a[i])
                {
                    return 0;
                }
            } 
        }
            if (i==len && k==patternLen-1)
            { 
            return 1;
            } 
            else
            { 
            return 0;
            }
}

void doIntegerBasedRounding(int a[], int n, int len) {
    // Before rounding
    printf("Before rounding: ");
    for (int i = 0; i < len; i++) {
        printf("%d ", a[i]);
    }
    printf("\n\n");

    // After rounding
    for (int i = 0; i < len; i++) {
        if (a[i] > 0 && n > 0) {
            int roundDown = (a[i] / n) * n;
            int roundUp = roundDown + n;

            if ((a[i] - roundDown) < (roundUp - a[i])) {
                a[i] = roundDown;
            } else {
                a[i] = roundUp;
            }
        }
    }

    // After rounding
    printf("After rounding: ");
    for (int i = 0; i < len; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int CubeCalculate(int n)
{   
    int cube = 1;
    for(int i = 0; i < 3; i++)
    {
        cube *= n;
    }
    return cube;
}

int isCubePowerful(int n)
{
    if(n <= 0)
    {
        return 0;
    }

    int sum = 0;
    int number = n;
    while(number > 0)
    {
        int digit = number%10;
        sum += CubeCalculate(digit);
        number = number/10;      
    }
    
    if(sum == n)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int decodeArray(int a[ ], int len)
{
    if(len == 1)
    {
        return 0;
    }

    int decodedNumber = 0;
    for(int i = 1; i < len; i++)
    {
        decodedNumber *= 10;
        decodedNumber += abs((a[i-1])-(a[i])); 
    }

    if(a[0] < 0)
    {
        return decodedNumber *= -1;
    }
    else
    {
        return decodedNumber;
    }
}

int isZeroPlentiful(int a[ ], int len)
{
    if(len < 4)
    {
        return 0;
    }

    int SeqSum = 0;
    int zeroSum = 0;
    for(int i = 1; i < len; i++)
    {
        if(a[i] == 0)
        {
            zeroSum++;
        }
        else
        {
            zeroSum = 0;
        }

        if(zeroSum == 4)
        {
            SeqSum++;
        }
    }

    return SeqSum;
}

int isDigitIncreasing(int n)
{
    int sum = 0;
    int found = 0;
    for(int i = 9; i > 0; i--)
    {
        int test = i;
        sum = 0;
        while(sum < n)
        {
            sum += test;
            test = ((test*10)+i);
        }
        if(sum == n)
        {
            found = i;
        }
    }
    
    if(found > 0)
    {
        return 1;
    }
    else
    {
        return found;
    }
}

int decodeArrayx(int a[ ], int len)
{
    int zeroCount = 0;
    int number = 0;
    for(int i = 0; i < len; i++)
    {
        if(a[i] == 0)
        {
            zeroCount++;
        }
        else if(a[i] != 0 && a[i-1] != 0)
        {
            number = (number * 10);
            zeroCount = 0;
        }
        else if(a[i] != 0 && a[i-1] == 0)
        {
            number = (number * 10) + zeroCount;
            zeroCount = 0;
        }
    }
    if(a[0] < 0)
    {
        number = (number * -1);
    }
    return number;
}

int isOnionArray(int a[], int len) {
    // Check if the length of the array is odd
    if (len % 2 == 0) {
        return 0; // If the length is even, it can't be an onion array
    }

    int i, j, k;
    // Iterate up to the middle of the array
    for (i = 0; i < len / 2; i++) {
        j = i;
        k = len - i - 1;

        // Check if the conditions are violated
        if (a[j] < 0 || a[k] < 0 || a[j] + a[k] > 10 || a[j] == a[k]) {
            return 0; // Not an onion array
        }
    }

    return 1; // If all conditions are satisfied, it's an onion array
}

int isPrimeHappy(int n)
{
    if(n <= 2)
    {
        return 0;
    }

    int sum = 0;
    for(int i = 2; i < n; i++)
    {
        if(isPrime(i) == 1)
        {
            sum+=i;
        }
    }

    if(sum%n == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isSystematicallyIncreasing(int a[ ], int len)
{
    int increasingIndex = 0;
    int incrementValue = 1;

    // Loop through the array
    while (increasingIndex < len) {

        int currentNumber = 1;
        // Loop through the increasing sequence
        for (int i = increasingIndex; i < (increasingIndex + incrementValue) && i < len; i++) {
            // Check if the current element matches the expected number in the sequence
            if (a[i] != currentNumber) {
                return 0;
            }
            currentNumber++;
        }

        increasingIndex += incrementValue; // Move to the next increasing sequence
        incrementValue++; // Increment the value for the next sequence
    }
    return 1;
}

int fac(int n)
{
    if(n == 0 || n == 1)
    {
        return 1;
    }
    else
    {
        return n*fac(n-1);
    }
}

int isFactorialPrime(int n)
{
    if(isPrime(n) == 0)
    {
        return 0;
    }

    for(int i = 1; i < n; i++)
    {
        if(isPrime(i) == 1 && fac(i)+1 == n)
        {
            return 1;
        }
    }

    return 0;
}

int largestDifferenceOfEvens(int a[ ], int len)
{
    int largestDiff = -1;
    SortArray_ASC(a,len);

    for(int i = 0; i < len; i++)
    {
        for(int j = i+1; j < len; j++)
        {
            if(a[j]%2 == 0 && a[i]%2 == 0 && a[j]-a[i] > largestDiff)
            {
                largestDiff = a[j]-a[i];
            }
        }
    }
    return largestDiff;
}

int isHodder(int n)
{
    if(isPrime(n) == 0)
    {
        return 0;
    }

    int hodder = 0;
    int limit = n/2;
    for(int i = 1; i <= n; i++)
    {
        if((pow(2,i)-1) == n)
        {
            hodder = 1;
            break;
        }
    }
    return hodder;
}

int areAnagrams(char a1[ ], char a2[ ], int len)
{
    int anagram = 0;
    for(int i = 0; i < len; i++)
    {
        for(int j = 0; j < len; j ++)
        {
            if(a1[i] == a2[j])
            {
                anagram++;
            }
        }
    }

    if(anagram == len)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int closestFibonacci(int n)
{
    if(n < 4)
    {
        return n-1;
    }

    int lastTerm = 2;
    int CurrentTerm = 3;
    int temp;
    while(CurrentTerm < n)
    {
        temp = CurrentTerm;
        CurrentTerm = CurrentTerm+lastTerm;
        lastTerm = temp;
    }

    return lastTerm;
}

int* computeHMS(int seconds)
{
    int SECS,MINS,HRS,one_hr = 3600,one_min = 60;

    HRS = (seconds)/(60*60);
    MINS = ((seconds)-(one_hr*HRS))/(60);
    SECS = ((seconds)-(one_hr*HRS)-(MINS*60));
    int* HMS = malloc(3*sizeof(int));
    HMS[0] = HRS;
    HMS[1] = MINS;
    HMS[2] = SECS;

    return HMS;
}

int isMartian(int a[ ], int len)
{
    int ones = 0, twos = 0;
    for(int i = 0; i < len; i++)
    {
        if(a[i] == a[i+1] && i != len-1)
        {
            return 0;
        }
        else if(a[i] == 1)
        {
            ones++;
        }
        else if(a[i] == 2)
        {
            twos++;
        }
    }
    if(ones > twos)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isPairedN(int a[ ], int n, int len)
{
    if(len == 1 && a[0] == n)
    {
        return 1;
    }
    else if(len == 1 && a[0] != n)
    {
        return 0;
    }
    else
    {}

    for(int i = 0; i < len; i++)
    {
        for(int j = i+1; j < len; j++)
        {
            if(i+j == n && a[i]+a[j] == n)
            {
                return 1;
            }
        }
    }
    return 0;
}

void updateMileageCounter(int a[], int miles, int len) {
    for (int i = 0; i < len && miles > 0; i++) {
        int diff = 9 - a[i]; // Calculate the difference to 9
        if (diff > 0) { // If there's room to add miles without rolling over
            if (diff >= miles) { // If we can add all miles without rolling over
                a[i] += miles;
                miles = 0;
            } else { // If we need to roll over
                a[i] = 0; // Roll over this digit
                miles -= diff + 1; // Subtract the miles rolled over plus the one added
            }
        }
    }
}


int main() 
{return 0;}