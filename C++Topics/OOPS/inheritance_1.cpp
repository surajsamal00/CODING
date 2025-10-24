class Base {
    public: 
        int x;
    protected: 
        int y;
    private: 
        int z;
};
/*
    |   members in base->       Public      Protected       Private       
    |   mode of inheritance
    |               Public :    Public      Protected       Nope
    |               Protected:  Protected   Protected       Nope
    |               Private:    Private     Private         Nope

*/
class Derived : public Base {
    void test() {       //mode Base->  public  protected private
        x = 1; // OK                   public 
        y = 2; // OK
        // z = 3; // ❌ Not accessible
    }
};
