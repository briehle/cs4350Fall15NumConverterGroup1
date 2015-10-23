#include <iostream>

using namespace std;

bool characteristic(char numString[], int& c);
bool mantissa(char numString[], int& numerator, int& denominator);
bool add(int c1, int n1, int d1, int c2, int n2, int d2, char result[], int len);
bool subtract(int c1, int n1, int d1, int c2, int n2, int d2, char result[], int len);
bool multiply(int c1, int n1, int d1, int c2, int n2, int d2, char result[], int len);
bool divide(int c1, int n1, int d1, int c2, int n2, int d2, char result[], int len);

int main()
{
    //some numbers to work with
    char number1[] = "   123.456";
    char number2[] = "-456  ";
    
    //a place for the answer
    char answer[100];
    
    //intermediate values
    int c1, n1, d1;
    int c2, n2, d2;
    
    //if the conversion from C string to integers can take place
    if(characteristic(number1, c1) && mantissa(number1, n1, d1) &&
       characteristic(number2, c2) && mantissa(number2, n2, d2))
    {
        //do some math with the numbers
        if(add(c1, n1, d1, c2, n2, d2, answer, 100))
        {
            //display string with answer -332.544
            cout<<"The sum of the numbers "<<number1<<" and "<<number2<<" is "<<answer<<endl;
        }
        else
        {
            //display error message
            cout<<"Cannot add the numbers: "<<number1<<" and "<<number2<<endl;
        }
        
        if(subtract(c1, n1, d1, c2, n2, d2, answer, 100))
        {
            //display string with answer 579.456
            cout<<"The difference of the numbers "<<number1<<" and "<<number2<<" is "<<answer<<endl;
        }
        else
        {
            //display error message
            cout<<"Cannot subtract the numbers: "<<number1<<" and "<<number2<<endl;
        }
        
        if(multiply(c1, n1, d1, c2, n2, d2, answer, 100))
        {
            //display string with answer -56295.936
            cout<<"The product of the numbers "<<number1<<" and "<<number2<<" is "<<answer<<endl;
        }
        else
        {
            //display error message
            cout<<"Cannot multiply the numbers: "<<number1<<" and "<<number2<<endl;
        }
        
        if(divide(c1, n1, d1, c2, n2, d2, answer, 100))
        {
            //display string with answer -0.27073684210526
            cout<<"The quotient of the numbers "<<number1<<" and "<<number2<<" is "<<answer<<endl;
        }
        else
        {
            //display error message
            cout<<"Cannot divide the numbers: "<<number1<<" and "<<number2<<endl;
        }
    }
    else
    {
        //handle the error on input
        cout<<"Error converting the strings into numbers: "<<number1<<" and "<<number2<<endl;
    }
    
    return 0;
}
//--
bool validateString(char numString[]);
int convertStringToInt(char numString[], int& length);
int lengthOfCharacteristicString(char numString[]);
bool characteristic(char numString[], int& c)
{
    bool retVal = true;
	//validate string
	if (!validateString(numString))
	{
		retVal = false;
	}
	else
	{
		//make new string with only characteristic
		int length = lengthOfCharacteristicString(numString);
		//change new string into an integer
		c = convertStringToInt(numString, length);
		if (length == -1)
			retVal = false;
	}
	
	return retVal;
}

bool isdigit(char c) {
    if(c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9')
        return true;
    else
        return false;
}
bool isValidCharacter(char c) {
    if((c =='+'|| c =='-'|| c=='\0'|| c =='.' || c ==' ')|| isdigit(c)) {
        return true;
    }
    return false;
}

int mantissaDenominatorHelper(int numerator){
    int denominator = 10;
    //if it is less than 10 you know it will be x/10
    if(numerator < 10){
        return denominator;
    }
    
    while(numerator >= 10){
        numerator /= 10;
        denominator *= 10;
    }
    
    return denominator;
}
int mantissaNumeratorHelper(char numString[])
{
    int decimalPos = -1;
    int val = 0;
    
    //Find decimal point index
    for(int i = 0; numString[i] !='\0'; i++)
    {
        if(numString[i] == '.')
        {
            decimalPos = i;
            break;
        }
    }
    
    //0/10 if no decimal point
    if(decimalPos >= 0){
        
        for(int i = decimalPos + 1; numString[i] != '\0'; i++){
            if(!isValidCharacter(numString[i])) {
                return -1;
            }
            if((numString[i] == '+' || numString[i] == '-') && i != 0){
                if(numString[i-1] != ' ') {
                    //this means that the + or - sign was not at the beginning of number
                    return -1;
                }
            }
            if(numString[i] == '.' && i != decimalPos) {
                // there is a second decimal point
                return -1;
            }
            //Check for trailing spaces
            if(numString[i] == ' '){
                if(numString[i + 1] != '\0' && numString[i + 1] != ' '){
                    if(i >= decimalPos + 1) {
                        return -1;
                    }
                }
            }
            //Don't overflow
            //Shaves off the last digit and accounts for whehter the digit is anything 0-9
            if(val >= 0 && (val < ((INT_MAX - 9)/10)))
                val = (val * 10) + (numString[i] - '0');
            else
            {
                cout << "THERE IS AN OVERFLOW IN THE NUMERATOR!" << endl;
                break;
            }
        }
    }
    
    return val;
}

bool mantissa(char numString[], int& numerator, int& denominator){
    //Set numerator and denominator
    numerator = mantissaNumeratorHelper(numString);
    if(numerator == -1){
        return false;
    }
    denominator = mantissaDenominatorHelper(numerator);
    
    return true;
}

//--
bool add(int c1, int n1, int d1, int c2, int n2, int d2, char result[], int len)
{
    //replace this code with your function
    return false;
}
//--
bool subtract(int c1, int n1, int d1, int c2, int n2, int d2, char result[], int len)
{
    //replace this code with your function
    return false;
}
//--
bool multiply(int c1, int n1, int d1, int c2, int n2, int d2, char result[], int len)
{
    //replace this code with your function
    return false;
}
//--
bool divide(int c1, int n1, int d1, int c2, int n2, int d2, char result[], int len)
{
    //replace this code with your function
    return false;
}


//-----------Characteristic Helpers------------------
bool validateString(char numString[])
{
	bool retVal = true;
	int numStartIndex = 0;
	//loops through to find the first non-space character
	if (numString[0] == ' ')
	{
		while (numString[numStartIndex] == ' ')
		{
			numStartIndex += 1;
		}
	}
	//if first charcter is not a number make sure it is either a '+' or '-'
	if (numString[numStartIndex] != '+' && numString[numStartIndex] != '-' && (numString[numStartIndex] < '0' || numString[numStartIndex] > '9'))
	{
		retVal = false;
	}
	else
	{
		//make sure there is only one '.' in the string
		//make sure all the characters are numbers besides the '.'
		int dotCounter = 0;
		bool isLetter = false;
		int i = numStartIndex + 1;
		bool isSpace = false;
		while (numString[i] != '\0')
		{
			//while we haven't hit a space yet
			if (!isSpace)
			{
				//keeps track of the number of decimal points in the number
				if (numString[i] == '.')
				{
					dotCounter += 1;
					if(dotCounter > 1)
						break;
				}
				//when we hit a space switch the boolean to true
				else if (numString[i] == ' ')
				{
					isSpace = true;
				}
				//if we hit a letter or other symbol
				else if (numString[i] < '0' || numString[i] > '9')
				{
					isLetter = true;
					break;
				}
			}
			else //here we have hit a space and we want to make sure there isn't any numbers after the space(s) and before the \0
			{
				if (numString[i] != ' ')
				{
					//only switch to false if we get to something other than a space or \0 after the first space
					retVal = false;
					break;
				}
			}
			i += 1;
		}
		if (dotCounter > 1 || isLetter)
		{
			retVal = false;
		}
	}

	return retVal;
}

int convertStringToInt(char numString[], int& length)
{
	bool isNegative = false;
	int finalNum = 0;
	int powerOfTen = 1;
	for (int i = length - 1; i >= 0; i--)
	{
		if (numString[i] == '-')
		{
			isNegative = true;
		}
		else if (numString[i] != ' ' && numString[i] != '+')
		{
			//convert char digit into integer
			int valOfDigit = numString[i] - '0';
			int overflowCheck = finalNum + (valOfDigit * powerOfTen);
			if (overflowCheck < finalNum)
			{
				//overflow
				length = -1; //just a flag to signify an overflow
			}
			else
			{
				//multiply the digit by the power of ten and add it to the final answer
				finalNum += (valOfDigit * powerOfTen);
				//move to the next power of 10
				powerOfTen *= 10;
			}
		}
	}

	return (isNegative ? -finalNum : finalNum);
}

int lengthOfCharacteristicString(char numString[])
{
	int numCharacters = 0;
	//this finds the number of characters in the characteristic, this will be used later to control a loop
	while (numString[numCharacters] != '.' && numString[numCharacters] != '\0')
	{
		numCharacters += 1;
	}

	return numCharacters;
}

//get the number of digits in number
int numDigits(int number)
{
    int digits = 0;
    
    if (number < 0) digits = 1;
    
    while (number)
    {
        number /= 10;
        digits++;
    }
    return digits;
}

//whole number division
int wholeNumberDivision(int top, char result[], int length, bool &isNegative)
{
    //getting the number of digits of the int
    int positionToAddNumbers = numDigits(top);
    
    //positionToAddNumbers changes so i made a copy of the original value
    int placeHolder = positionToAddNumbers;
    
    //add top to result array
    //if top is a single digit
    if (top < 10)
    {
        //if its negative add the - sign
        if (isNegative)
        {
            top*=-1;
            result[positionToAddNumbers-1] = (char)top;
            top*=-1;
            
            //turn off is negative
            isNegative = false;
        }
        
        else
        {
            //add value to result
            result[positionToAddNumbers-1] = (char)top;
        }
    }
    
    int onesPlace;
    
    //if top is more then one digit
    while (top >= 10)
    {
        //getting one's place from digit
        onesPlace = top % 10;
        
        //adding to result
        result[positionToAddNumbers-1] = (char)onesPlace;
        
        positionToAddNumbers--;
        
        //removing ones place
        top/= 10;
        
        if (top <= 9)
        {
            //adding last digit
            //if its negative add the - sign
            if (isNegative)
            {
                top*=-1;
                result[positionToAddNumbers-1] = (char)top;
                top*=-1;
                
                //turn off is negative
                isNegative = false;
            }
            
            //add digit as normal
            else
            {
                result[positionToAddNumbers-1] = (char)top;
            }
        }
    }
    
    //returning number of digits
    return placeHolder;
}

void longDivisionHelper(int n, int d, char result[], int length, bool &isNegative)
{
    int top = n / d;
    int bottom = n % d;
    
    //position to start adding more digits
    int positionToStartAt = wholeNumberDivision(top, result, length, isNegative);
    
    //adding the . at the postion we ended at earlier
    result[positionToStartAt] = '.';
    
    //loop to do long division
    for (int i = positionToStartAt + 1; i < length; i++)
    {
        //"bringing down" the zero
        bottom *= 10;
        
        //answer from long division
        top = bottom / d;
        
        //for adding the - sign
        if (isNegative)
        {
            result[i] = (char)top;
            isNegative = false;
        }
        
        //if the other numbers are negative we dont want lots of - signs
        else
        {
            result[i] = (char)top;
        }
        
        //subtracting top value * d from bottom
        bottom -=top * d;
    }
}

bool divide(int c1, int n1, int d1, int c2, int n2, int d2, char result[], int len)
{
    //boolean for if the user placed negative numbers
    bool isNegative = false;
    
    //check if dividing by zero
    if (d1 == 0 || d2 == 0)
    {
        return false;
    }
    
    //making numbers improper
    if (c1 != 0)
    {
        n1 = n1 + (d1 * c1);
    }
    
    if (c2 != 0)
    {
        n2 = n2 + (d2 * c2);
    }
    
    //removing d2
    n1 *= d2;
    
    //removing n2
    d1 *= n2;
    
    //checking for negatives
    //if n1 is negative
    if (n1 < 0 && d1 > 0)
    {
        n1*=-1;
        isNegative = true;
    }
    //if d1 is negative
    else if (n1 > 0 && d1 < 0)
    {
        d1*=-1;
        isNegative = true;
    }
    
    //if both are negative then remove negatives
    else if (n1 < 0 && d1 < 0)
    {
        n1*=-1;
        d1*=-1;
    }
    
    longDivisionHelper(n1, d1, result, len, isNegative);
    
    return true;
}