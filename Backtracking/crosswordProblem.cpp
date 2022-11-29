/*
Coding Ninjas has provided you a crossword of 10*10 crossword. The crossword contains '+' or '-' as its cell values. Now, you are also provided with a s list that needs to placed accurately in the crossword. Cells marked with '-' are to be filled with s list.
For example, The following is an example for the input crossword crossword and the s list.
+-++++++++
+-++-+++++
+-------++
+-++-+++++
+-++-+++++
+-++-+++++
++++-+++++
++++-+++++
++++++++++
----------
CALIFORNIA;NIGERIA;CANADA;TELAVIV
Output for the given input should be:
+C++++++++
+A++T+++++
+NIGERIA++
+A++L+++++
+D++A+++++
+A++V+++++
++++I+++++
++++V+++++
++++++++++
CALIFORNIA
Note: We have provided such test cases that there is only one solution for the given input.
Input format:
The first 10 lines of input contain crossword. Each of 10 lines has a character array of size 10. Input characters are either '+' or '-'.
The next line of input contains the s list, in which each s is separated by ';'. 
Output format:
Print the crossword crossword, after placing the words of s list in '-' cells.  
Constraints
The number of words in the s list lie in the range of: [1,6]
The length of words in the s list lie in the range: [1, 10]
Time Limit: 1 second
Sample Input 1:
+-++++++++
+-++-+++++
+-------++
+-++-+++++
+-++-+++++
+-++-+++++
++++-+++++
++++-+++++
++++++++++
----------
CALIFORNIA;NIGERIA;CANADA;TELAVIV
Sample Output 1:
+C++++++++
+A++T+++++
+NIGERIA++
+A++L+++++
+D++A+++++
+A++V+++++
++++I+++++
++++V+++++
++++++++++
CALIFORNIA
*/

#include<bits/stdc++.h>
using namespace std;
#define n 10

void printer(char cross[n][n]){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << cross[i][j] ;
        }
        cout << endl;
    }
}

bool isValidVertical(char cross[n][n],int r,int c,string word)
{
    int j = r;
    for(int i=0;i<word.length();i++)
    {
        if(j > 9)
        {
            return false;
        }
        if(cross[j][c] == '+' || ((cross[j][c] != '-' && cross[j][c] != word[i])))
        {
            return false;
        }
        if(cross[j][c] == '-' || cross[j][c] == word[i])
        {
            j++;
        }
    }
    return true;
}

void setVertical(char cross[n][n],int r,int c,vector<bool>& v,string word){
    for(int i=0;i<word.length();i++){
        if(cross[r+i][c] == '-'){
            cross[r+i][c] = word[i];
            v.push_back(true);
        }else{
            v.push_back(false);
        }
    }
}

void resetVertical(char cross[n][n],int r,int c,vector<bool> v){
    int row = r;
    for(int i=0;i<v.size();i++){
        if(v[i]){
            cross[row+i][c] = '-';
        }
    }
}

bool isValidHorizontal(char cross[n][n],int r,int c,string word){
    int j = c;
    for(int i=0;i<word.length();i++){
        if(j > 9){
            return false;
        }
        if(cross[r][j] == '+' || (cross[r][j] != '-' && cross[r][j] != word[i])){
            return false;
        }
        if(cross[r][j] == '-' || cross[r][j] == word[i]){
            j++;
        }
    }
    return true;
}

void setHorizontal(char cross[n][n],int r,int c,vector<bool>& v,string word){
    for(int i=0;i<word.length();i++){
        if(cross[r][c+i] == '-'){
            cross[r][c+i] = word[i];
            v.push_back(true);
        }else{
            v.push_back(false);
        }
    }
}

void resetHorizontal(char cross[n][n],int r,int c,vector<bool> v){
    int col = c;
    for(int i=0;i<v.size();i++){
        if(v[i]){
            cross[r][col+i] = '-';
        }
    }
}


bool crossword(char cross[n][n],vector<string> words,int index)
{
    if(index >= words.size())
    {
        printer(cross);
        return true;
    }
    for(int r=0;r<n;r++)
    {
        for(int c=0;c<n;c++)
        {    
            if(cross[r][c] == '-' || cross[r][c] == words[index][0])
            {
                if(isValidVertical(cross,r,c,words[index]))
                {
                    vector<bool> helper;
                    setVertical(cross,r,c,helper,words[index]);
                    if(crossword(cross,words,index+1))
                    {
                        return true;
                    }
                    resetVertical(cross,r,c,helper);
                }
                if(isValidHorizontal(cross,r,c,words[index]))
                {
                    vector<bool> helper;
                    setHorizontal(cross,r,c,helper,words[index]);    
                    if(crossword(cross,words,index+1))
                    {
                        return true;
                    }
                    resetHorizontal(cross,r,c,helper);
                }
            }
        }
    }
    return false;
}

int main(){
    char cross[n][n];
    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        for(int j=0;j<n;j++){
            cross[i][j] = s[j];
        }
    }
    vector<string> words;
    string s;
    cin >> s;
    for(int i=0;i<s.length();i++){
        int j = i;
        while(s[j] != ';' && j < s.length()){
            j++;
        }
        words.push_back(s.substr(i,j-i));
        i = j; 
    }
    bool ans = crossword(cross,words,0);
    
    return 0;
}

//following code is correct
// #include<bits/stdc++.h>
// using namespace std;

// char crossWord[10][10];
 
// bool isValidHorizontal(int row, int col, string word){
 
// 	if(10 - col < word.length())
// 		return false;
 
// 	for (int i = 0, j = col; i < word.length(); ++i,j++)
// 	{
// 		if (crossWord[row][j] != '-' && crossWord[row][j] != word[i]){
// 			return false;
// 		}
// 	}
 
// 	return true;
// }
 
// bool isValidVertical(int row, int col, string word){
 
// 	if(10 - row < word.length())
// 		return false;
 
// 	for (int i = row, j = 0; j < word.length(); ++i,j++)
// 	{
// 		if (crossWord[i][col] != '-' && crossWord[i][col] != word[j]){
// 			return false;
// 		}
// 	}
 
// 	return true;
// }
 
// void setHorizontal(int row, int col, string word, bool state[]){
 
// 	for (int i = 0, j = col; i < word.size(); ++i, j++)
// 	{
// 		if (crossWord[row][j] != '+'){
 
// 			if(crossWord[row][j] == word[i])
// 				state[i] = false;
// 			else
// 				state[i] = true;
// 			crossWord[row][j] = word[i];
// 		}
 
// 	}
// }
 
// void setVertical(int row, int col, string word, bool state[]){
 
// 	for (int i = 0, j = row; i < word.size(); ++i, j++)
// 	{
// 		if (crossWord[j][col] != '+'){
 
// 			if(crossWord[j][col] == word[i])
// 				state[i] = false;
// 			else
// 				state[i] = true;
// 			crossWord[j][col] = word[i];
// 		}
 
// 	}
// }
 
// void resetHorizontal(int row, int col, bool state[], int size){
 
// 	for (int i = 0, j = col; i < size; ++i,j++)
// 	{
// 		if(state[i] == true)
// 			crossWord[row][j] = '-';
// 	}
// 	return;
// }
 
// void resetVertical(int row, int col, bool state[], int size){
 
// 	for (int i = 0, j = row; i < size; ++i,j++)
// 	{
// 		if(state[i] == true)
// 			crossWord[j][col] = '-';
// 	}
// 	return;
// }
 
// void set_value(bool helper[],int len ){
// 	for(int i=0;i<len;i++){
// 		helper[i] = false;
// 	}
// }
 
 
// bool crossWordHelper(string input[], int size, int index){
 
// 	if(index == size){
// 		for(int i =0; i<10; i++){
// 			for(int j=0; j<10; j++){
 
// 				cout << crossWord[i][j] ;
// 			}
// 			cout << endl;
// 		}
// 		return true;
// 	}
 
// 	for(int i =0; i<10; i++){
// 		for(int j=0; j<10; j++){
 
// 			if(crossWord[i][j] == '-' || crossWord[i][j] == input[index][0]){
// 				int length = input[index].size();
// 				bool state[length];
// 				set_value(state,length);
 
// 				if(isValidHorizontal(i, j, input[index])){
// 					setHorizontal(i, j, input[index], state);
// 					if(crossWordHelper(input, size, index+1)){
// 						return true;
// 					}
// 					resetHorizontal(i, j, state, length);
// 				}
 
// 				if(isValidVertical(i, j, input[index])){
// 					setVertical(i, j, input[index], state);
// 					if(crossWordHelper(input, size, index+1)){
// 						return true;
// 					}
// 					resetVertical(i, j, state, length);
// 				}
 
// 			}
// 		}
// 	}
// 	return false;
// }
 
// void solveCrossWord(string input[], int size){
 
// 	bool res = crossWordHelper(input, size, 0);
// 	return;
// }
 
// int main(){
// 	string ss;
// 	for(int i = 0; i<10; i++){
// 		cin >>ss;
// 		for(int j = 0; j < ss.size(); j++){
// 			crossWord[i][j] =  ss[j];
// 		}
// 	}
 
// 	char s[200];
// 	cin >> s;
 
// 	string input[10];
// 	char ch;
// 	string word ="";
// 	int a =0;
// 	for (int i = 0; s[i] != '\0'; ++i)
// 	{
 
// 		if(s[i] == ';'){
// 			input[a++] = word;
// 			word ="";
// 		}
// 		else {
// 			word += s[i];
// 		}
// 	}
// 	input[a++] = word;
 
// 	solveCrossWord(input, a);
// return 0;
// }


//following code was giving wrong ans in all test cases
// void print(char crossword[10][10]){
//     for(int i = 0; i < 10; i++){
//         for(int j = 0; j < 10; j++){
//             cout<<crossword[i][j];
//         }
//         cout<<endl;
//     }
// }

// bool isValidHorizontal(char crossword[10][10], string str, int row, int col){
//     for(int i = col, j = 0; i < col + str.length(); i++, j++){
//         if(crossword[row][i] == '+' || crossword[row][i] != str[j] || i > 10){
//             return false;
//         }
//     }
//     return true;
// }

// void setHorizontal(char crossword[10][10], string str, bool arr[], int row, int col){
//     for(int i = col, j = 0; i < col + str.length(); i++, j++){
//         if(crossword[row][i] == str[j]){
//             arr[j] = false;
//         }
//         else if(crossword[row][i] == '-'){
//             arr[j] = true;
//         }
//         crossword[row][i] = str[j];    
//     }
// }

// void resetHorizontal(char crossword[10][10], string str, bool arr[], int row, int col){
//     for(int i = col, j = 0; i < col + str.length(); i++, j++){
//         if(arr[j]){
//             crossword[row][i] = '-';
//         }
//     }
// }

// bool isValidVertical(char crossword[10][10], string str, int row, int col){
//     for(int i = row, j = 0; i < row + str.length(); i++, j++){
//         if(crossword[i][col] == '+' || crossword[i][col] != str[j] || i > 10){
//             return false;
//         }
//     }
//     return true;
// }

// void setVertical(char crossword[10][10], string str, bool arr[], int row, int col){
//     for(int i = row, j = 0; i < row + str.length(); i++, j++){
//         if(crossword[i][col] == str[j]){
//             arr[j] = false;
//         }
//         else if(crossword[i][col] == '-'){
//             arr[j] = true;
//         }
//         crossword[i][col] = str[j];
//     }
// }

// void resetVertical(char crossword[10][10], string str, bool arr[], int row, int col){
//     for(int i = row, j = 0; i < row + str.length(); i++, j++){
//         if(arr[j]){
//             crossword[i][col] = '-';
//         }
//     }
// }

// bool crossWordSolver(char crossword[10][10], string s[], int index){
//     if(index == s -> length()){
//         print(crossword);
//         return true;
//     }

//     for(int i = 0; i < 10; i++){
//         for(int j = 0; j < 10; j++){
//             string str = s[index];
//             if(crossword[i][j] == '-' || crossword[i][j] == s[index][0]){
//                 if(isValidVertical(crossword, str, i, j)){
//                     int size = str.length();
//                     bool arr[size];
//                     for(int i = 0; i < size; i++){
//                         arr[i] = false;
//                     }
//                     setVertical(crossword, str, arr, i, j);
//                     if(crossWordSolver(crossword, s, index + 1)){
//                         return true;
//                     }
//                     resetVertical(crossword, str, arr, i, j);
//                 }

//                 if(isValidHorizontal(crossword, str, i, j)){
//                     int size = str.length();
//                     bool arr[size];
//                     for(int i = 0; i < size; i++){
//                         arr[i] = false;
//                     }
//                     setHorizontal(crossword, str, arr, i, j);
//                     if(crossWordSolver(crossword, s, index + 1)){
//                         return true;
//                     }
//                     resetHorizontal(crossword, str, arr, i, j);
//                 }
//             }
//         }
//     }

// }

// int main(){
//     char crossword[10][10];
//     string ss;
//     for(int i = 0; i < 10; i++){
//         cin>>ss;
//         for(int j = 0; j < ss.size(); j++){
//             crossword[i][j] = ss[j];
//         }
//     }
    
//     char input[200];
//     cin>>input;
//     string s[10];
//     int a = 0;
//     string word = "";
//     for(int i = 0; input[i] != '\0'; i++){
//         if(input[i] == ';'){
//             s[a++] = word;
//             word = "";
//         }
//         else{ 
//             word += input[i];
//         }
//     }
//     s[a] = word;
//     crossWordSolver(crossword, s, 0);
// }