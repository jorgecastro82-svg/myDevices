#include <iostream>
#include <vector>
#include <cmath>

using std::cout,std::cin,std::endl,std::vector;

int main(){

    double interest = 0;
    cout << "Give me your interest rate: " << endl;
    cin >> interest;

    //loop to ask for all periods and store them into period vector
    vector<double> periods;
    double aux;
    cout << "Give me the flow of your periods (if is a loss put them negative): " << endl;
    while(cin >> aux)
        periods.push_back(aux);
    
    //converting them to period 0;
    int i = 0;
    double fne = 0;
    for(auto &period : periods){
        fne += period = (period) / pow((1 + interest),++i);
    }

    //printing the info
    //and also storing the positives and negativces
    vector<double> win,loss;
    i = 0;
    for(auto period: periods){
        cout << "Period " << ++i << " converted to 0: " << period << "\n";
        if(period >= 0)
            win.push_back(period);
        else
            loss.push_back(period);
    }

    double sum = 0;
    for(auto winn : win)
        sum += winn;

    cout << "Wins are: " << sum << endl;

    sum = 0;
    for(auto lost : loss)
        sum += lost;

    cout << "Losses are: " << sum << endl;
    
    cout << "FNE is: " << fne << endl;


    return 0;
}