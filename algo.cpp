#include "libraries.h"
using namespace std;

// golbal variables
int batsmen;
int bowlers;
int overs;
int overs_per_batsman; //
int overs_per_bowler;  //
int fielders_from_batting_side;
int fielders_from_bowlers_side;
int battingside_rotation_per_overs;
int bowlingside_rotation_per_overs;

vector<int> possible_overs;

// functions
void init()
{
    batsmen = 0;
    bowlers = 0;
    overs = 0;
    overs_per_batsman = 0;
    overs_per_bowler = 0;
    fielders_from_batting_side = 0;
    fielders_from_bowlers_side = 0;
    battingside_rotation_per_overs = 0;
    bowlingside_rotation_per_overs = 0;
}

int selectBatsmen()
{
    cout << "select batsmen :";
    cin >> batsmen;

    if (batsmen < MIN_BATSMEN && batsmen > MAX_BATSMEN)
        return 1;
    else
        return 0;
}

int selectBowlers()
{
    cout << "select bowlers :";
    cin >> bowlers;

    if (lcm(batsmen, bowlers) > MAX_OVERS_ALLOWED)
        return 1;
    else
        return 0;
}

void oversSelect()
{
    cout << "Over choices : ";

    int temp = lcm(batsmen, bowlers);

    int i = 1;
    while (temp <= MAX_OVERS_ALLOWED)
    {
        i++;
        cout << temp << " ";
        possible_overs.push_back(temp);
        temp = temp * i;
    }
    cout << endl;

    cout << "Enter total overs you want: ";

    int inputTemp = 0;
    cin >> inputTemp;

    bool flag = true;

    for (int i = 0; i < possible_overs.size(); i++)
    {
        if (inputTemp == possible_overs[i])
        {
            flag = false;
            overs = possible_overs[i];
            overs_per_batsman = possible_overs[i] / batsmen;
            overs_per_bowler = possible_overs[i] / bowlers;
            cout << "Overs selected: " << overs << endl;
            cout << "overs per batsman: " << possible_overs[i] / batsmen << endl;
            cout << "Overs per bowler: " << possible_overs[i] / bowlers << endl;
            break;
        }
    }

    if (flag)
        cout << "Invalid Input !!!" << endl;
}

int selectCombinationFielders()
{
    int tempbatsmen;
    int tempbowlers;
    cout << "select batsmen for fielding from range : " << 0 << " - " << batsmen - 1 << " : ";
    cin >> tempbatsmen;
    cout << "select bowlers for fielding from tange : " << 0 << " - " << bowlers - 1 << " : ";
    cin >> tempbowlers;

    if ((tempbatsmen < 0 || tempbatsmen >= batsmen) || (tempbowlers < 0 || tempbowlers >= bowlers))
        return 0;
    else
    {
        fielders_from_batting_side = tempbatsmen;
        fielders_from_bowlers_side = tempbowlers;

        return 1;
    }
}

int selectRotation()
{
    vector<int> bowlerRotationVect;
    cout << "Rotation for bowlers: ";

    for (int i = 0; i <= sqrt(overs_per_bowler); i++)
    {
        if (overs_per_bowler % i == 0)
        {
            bowlerRotationVect.push_back(i);
            cout << i << " ";
        }
    }
    cout << endl;

    cout<<"Select battingside rotation choice from above: ";
    cin>>bowlingside_rotation_per_overs;


    vector<int> batsmanRotationVect;
    cout << "Rotation for bowlers: ";

    for (int i = 0; i <= sqrt(overs_per_batsman); i++)
    {
        if (overs_per_batsman % i == 0)
        {
            batsmanRotationVect.push_back(i);
            cout << i << " ";
        }
    }
    cout << endl;

    cout<<"Select bowlerside rotation choice from above: ";
    cin>>bowlingside_rotation_per_overs;

}

int main()
{
    init();

    // select batsmen
    if (selectBatsmen())
    {
        cout << "Invalid Input" << endl;
        return 1;
    }

    // select bowlers
    if (selectBowlers())
    {
        cout << "Invalid Input" << endl;
        return 1;
    }

    // select total overs
    oversSelect();

    // select combination of fielders
    if (selectCombinationFielders())
    {
        cout << "Invalid Input" << endl;
        return 1;
    }

    // Rotation choices allowed for batsmen and bowlers
    if (selectRotation())
    {
        cout << "Invalid Input" << endl;
        return 1;
    }
}