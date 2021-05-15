//   line 136 need to explain //  
//---------------------------//

#include <iostream>
#include <string>
#include <fstream>
#include <utility>
#include <queue>
#include <iomanip>

using namespace std;

enum State
{
    SN = 0,  
    WN = 1,  
    WT = 2,  
    ST = 3 
}; // 00, 01, 10, 11

typedef struct
{
    int history = 0; //00, 01, 10, 11 : 0, 1, 2, 3
    State state[4] = {SN, SN, SN, SN};  
} Func;

void print(int cont, char outcome, char prediction, Func table, bool check = false)
{
    cout << setfill(' ') << setw(2) << cont;
    // * print the current situation and prediction each time * //
    cout << "   (" << table.history / 2 << table.history % 2 << ", ";
    for (int i = 0; i < 4; i++)
    {
        switch (table.state[i])
        {
        case 0:
            cout << "SN";
            break;
        case 1:
            cout << "WN";
            break;
        case 2:
            cout << "WT";
            break;
        default:
            cout << "ST";
            break;
        }

        if (i == 3)
            cout << ")";
        else
            cout << ", ";
    }

    // * print the predicion and real outcome each time * //
    cout << setfill(' ') << setw(11) << prediction << setw(14) << outcome << setw(16) ;

    if (check)
        cout << " Yes!\n";
    else
        cout << "  No \n";
};

int give_history_value(string input, int history = -1)
{
    // * give a value to the 2-bit history * //
    if (input[0] == 78 && input[1] == 78)
    { //NN
        history = 0;
    }
    else if (input[0] == 78 && input[1] == 84) //NT
    {
        history = 1;
    }
    else if (input[0] == 84 && input[1] == 78) //TN
    {
        history = 2;
    }
    else if (input[0] == 84 && input[1] == 84) //TT
    {
        history = 3;
    }

    return history;
};

void state_change(Func& table, char prediction, string input)
{

    switch(table.state[table.history]){
        case 0:
        case 1:
            if (prediction != input[2])
                table.state[table.history] = (State)(table.state[table.history] + 1 > 3 ? 3 : (table.state[table.history] + 1));
            else
                table.state[table.history] = (State)(table.state[table.history] - 1 < 0 ? 0 : (table.state[table.history] - 1));
            break;
        default:
            if (prediction != input[2])
                table.state[table.history] = (State)(table.state[table.history] + 1 > 3 ? 3 : (table.state[table.history] - 1));
            else
                table.state[table.history] = (State)(table.state[table.history] - 1 < 0 ? 0 : (table.state[table.history] + 1));
            break;
    }
};


int main(int argc, char *argv[])
{
    // * input * //
    ifstream file;
    string input;

    // * open file and idiot-proof * //
    file.open(argv[1]);
    while (!file)
    {
        cout << "Can't open the file. Please enter the RIGHT file name again.\n";
        return 0;
    }

    // * content processing * //
    int counter = 0;
    Func state_table;
    char prediction = 'N';
    bool incorrect = false;
    while (getline(file, input))
    {
        cout << "The input is : " << input << endl;
        cout << "       Counter            Prediction     Outcome     Missing(Y/N)  " <<endl;
        cout.width(69);
        cout << cout.fill('-') << endl;

//*************// * if start from the 00 * //*************//
        //print(++counter, input[2], prediction, state_table, incorrect);  //thefirst  time 
//*************// * if start from the 00 * //*************//

        while (input.length() > 2)
        {
                // * give a value to the 2-bit history * //
                state_table.history = give_history_value(input);
                
                // * get a prediction * //
                switch ( state_table.state[ state_table.history ] )
                {
                    case 0:  //SN
                    case 1:  //WN
                        prediction = 78;  //N
                        break;
                    default:  //WT, ST
                        prediction = 84;  //T
                        break;
                }

                /*
                if (!counter++)
                {
                    prediction = 78; //N, because start from (0, 0)
                    state_table.history = 0;
                }
                */
                if(prediction != input[2])
                    incorrect = true;
                print(++counter,input[2], prediction, state_table, incorrect);


                state_change(state_table, prediction, input);
                
 

            // * pop the first element * //
            input = input.substr(1, input.length() - 1);

            incorrect = false;
        }
    }
}
