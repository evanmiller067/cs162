//This program demos arrays
#include <iostream>
#include <iomanip>
using namespace std;

const int ROWS = 2;
const int COLS = 3;

//function prototypes
void calcAvg(int scores[][COLS], int rows);

int main()
{
    int scores[ROWS][COLS] = {0};
    cout << "Please enter 6 scores:";
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            cin >> scores[i][j];
        }
    }
    //output the whole array
    
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            cout << scores[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
	calcAvg(scores, ROWS);
    return 0;
}

//function to calculate average
void calcAvg(int scores[][COLS], int rows)
{
	double total = 0, avg = 0;
	 //calculate the quiz average for each student
    for(int i = 0; i < rows; i++)
    {
        total = 0;
        for(int j = 0; j < COLS; j++)
        {
            total += scores[i][j];
        }
        avg = static_cast<double>(total) / COLS;
        cout << "Average of student " << i + 1 << " = " << avg << endl;
    }

}
