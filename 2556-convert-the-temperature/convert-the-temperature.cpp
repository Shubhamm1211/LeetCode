class Solution {
public:
    vector<double> convertTemperature(double Celsius) {
        double k=Celsius + 273.15;
        double f=Celsius * 1.80 + 32.00;
        return {k,f};
    }
};