template <typename T, typename V>

class Pair{
    T x;    //x is of type T
    V y;    //y is of type V

    public :

    void setX(T x){
        this -> x = x;
    }

    void setY(V y){
        this -> y = y;
    }

    T getX(){
        return x;
    }

    V getY(){
        return y;
    }


};