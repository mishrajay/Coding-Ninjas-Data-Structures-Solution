class student {
    static int totalStudents;

    public :

    student() {
        totalStudents++;
    }
    
    //static function
    //static functions do not have "this" keyword.
    static int getTotalStudents(){
        return totalStudents;  //static function can only access static data members or static function 
    }

};

int student :: totalStudents = 0; //initialising static member