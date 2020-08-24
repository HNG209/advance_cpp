#include<iostream>
using namespace std;
enum class color{
    RED,
    GREEN,
    BLUE
};
enum class fruit{
    APPLE,
    ORANGE,
    MANGO
};
template<typename T>
struct s{
    static string getName(int index){
        T temp = static_cast<T>(index);
        string t_name = static_cast<string>(typeid(temp).name());
        if (t_name == "5fruit")
        {
            switch (index)
            {
            case 0: return "APPLE";break;
            case 1: return "ORANGE";break;
            case 2: return "MANGO";break;
            default:
                break;
            }
        }
        else{
            switch (index)
            {
            case 0: return "RED";break;
            case 1: return "GREEN";break;
            case 2: return "BLUE";break;
            default:
                break;
            }   
        }
        return "unknown";
    }
};
template<typename T>
class Traits{
    public:
    string operator[](int index){
        T temp = static_cast<T>(index);
        string t_name = static_cast<string>(typeid(temp).name());
        if(t_name == "5fruit"){
            switch (index)
            {
                case 0: return "APPLE";break;
                case 1: return "ORANGE";break;
                case 2: return "MANGO";break;
            default:
                break;
            }
        }
        else{
            switch (index)
            {
                case 0: return "RED";break;
                case 1: return "GREEN";break;
                case 2: return "BLUE";break;
            default:
                break;
            }
        }
        return "unknown";
    }
};
int main(){
    cout << "enter looping time:";
    int t{};
    cin >> t;
    while(t--){
        cout << "enter index of color:";
        Traits<color> c;
        Traits<fruit> f;
        int i1,i2;
        cin >> i1;
        cout << "enter index of fruit:";
        cin >> i2;
        cout << "color index:" << c[i1];
        cout << ",fruit index:" << f[i2];
        cout << "\n";
    }
    return 0;
}