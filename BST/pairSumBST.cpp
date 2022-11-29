/*Given a binary tree and an integer S, print all the pair of nodes whose sum equals S.
Note:
1. Assume the given binary tree contains all unique elements.
2. In a pair, print the smaller element first. Order of different pairs doesn't matter.
Input format :
The first line of input contains data of the nodes of the tree in level order form. 
The data of the nodes of the tree is separated by space. If any node does not have a 
left or right child, take -1 in its place. Since -1 is used as an indication whether 
the left or right nodes exist, therefore, it will not be a part of the data of any node.
The following line of input contains an integer, that denotes the value of S.
Output Format :
Print each pair in a new line, as described in the task. 
Constraints:
Time Limit: 1 second
Sample Input 1:
5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
15
Sample Output 1:
5 10
6 9
*/
#include<iostream>
using namespace std;
#include"BSTheaderFile.cpp"
#include<algorithm>
void treeToArray(int *arr, BinaryTreeNode<int> *root, int *i){
    if(root == NULL){
        return;
    }
    
    arr[*i] = root -> data;
    *(i) = *(i) + 1;
    treeToArray(arr, root -> left, i);
    treeToArray(arr, root -> right, i);  
}

void pairSum(BinaryTreeNode<int> *root, int sum) {
    // Write your code here
    int arr[100];
    int i = 0;
    treeToArray(arr, root, &i);
    sort(arr, arr + i);
    int x = 0, y = i - 1;
    while(x < y){
        if(arr[x] + arr[y] < sum){
            x++;
        }
        else if(arr[x] + arr[y] > sum){
            y--;
        }
        else{
            cout<<arr[x]<<" "<<arr[y]<<endl;
            x++;
            y--;
        }
    }
    
}

int main() {
    BinaryTreeNode<int>* root = takeInputLevelWise();
    int sum;
    cin >> sum;
    pairSum(root, sum);
    delete root;
}