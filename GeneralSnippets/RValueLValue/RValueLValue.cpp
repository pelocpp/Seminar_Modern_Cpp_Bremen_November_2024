// =====================================================================================
// LValue / RValue
// =====================================================================================

module modern_cpp:rvalue_lvalue;

namespace LValueRValue {

    // lvalue reference
    static void sayHello(std::string& message) {
        std::println("sayHello [std::string&]:  {}", message);
    }

    // rvalue reference
    static void sayHello(std::string&& message) {
        std::println("sayHello [std::string&&]: {}", message);
    
      //  std::string tmp = std::move(message);
    
    }

    static void test01() {

        std::string a = "Hello";
        std::string b = " World";

        sayHello(a);
        sayHello(a + b);
    }

    // -------------------------------------------------------------------

    static void helper(std::string&& message) {

        sayHello(message);

        sayHello( std::move ( message) );
  
                     // ==> sayHello(std::string&&)
                     //         Der Parameter ist vom gleichen Typ
                     // ==> sayHello(std::string&)
                     //      Hmmm .. message ist aber ein Name für ein Objekt
    }

    static void test02() {

        //std::string a = "ABC";
        //helper(a);

        helper(std::string("Where are we going ..."));
    }

    // -------------------------------------------------------------------

    static void test03() {

        std::string s = "Hello";

        sayHello(s);
        // versus
        sayHello(std::move(s));  // casts an lvalue to an rvalue
    }


    // -------------------------------------------------------------------

    static void test03_seminar() {

        std::string s = "Hello";

        sayHello(s);

       //std::string s2 (std::move(s));  // Move-Konstruktor
        // s2 = std::move(s);  // Wertzuweisung

       // sayHello(std::move(s));  // casts an lvalue to an rvalue

        sayHello( std::string { std::move(s) } );
    }

    // -------------------------------------------------------------------

    static void test04() {

        // int& i = 2;          // invalid: reference to a constant

        // int a = 2;
        // int b = 3;

        // int& k = a + b;     // invalid: reference to a temporary

        int&& i = 2;           // works: reference to a constant

        int a = 2;
        int b = 3;

        int&& k = a + b;       // works: reference to a temporary
    }
}

void main_rvalue_lvalue()
{
    using namespace LValueRValue;
    //test01();
    //test02();
    //test03();
    //test04();

    test03_seminar();
}

// =====================================================================================
// End-of-File
// =====================================================================================
