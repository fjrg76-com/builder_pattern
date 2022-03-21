#include <iostream>

using namespace std;


class Ingredient1
{
public:
   virtual void exec1() = 0;
};

class Ingredient1_Kind1 : public Ingredient1
{
public:
   Ingredient1_Kind1()
   {
      cout << "Ingredient1_Kind1 constructor...\n";
   }

   void exec1()
   {
      cout << "Executing: Ingredient1_Kind1\n";
   }
};

class Ingredient1_Kind2 : public Ingredient1
{
public:
   Ingredient1_Kind2()
   {
      cout << "Ingredient1_Kind2 constructor...\n";
   }

   void exec1()
   {
      cout << "Executing: Ingredient1_Kind2\n";
   }
};


//----------------------------------------------------------------------
//  
//----------------------------------------------------------------------

class Ingredient2
{
public:
   virtual void exec2() = 0;
};

class Ingredient2_Kind1 : public Ingredient2
{
public:
   Ingredient2_Kind1()
   {
      cout << "Ingredient2_Kind1 constructor...\n";
   }

   void exec2()
   {
      cout << "Executing: Ingredient2_Kind1\n";
   }
};

class Ingredient2_Kind2 : public Ingredient2
{
public:
   Ingredient2_Kind2()
   {
      cout << "Ingredient2_Kind2 constructor...\n";
   }

   void exec2()
   {
      cout << "Executing: Ingredient2_Kind2\n";
   }
};


//----------------------------------------------------------------------
//  
//----------------------------------------------------------------------

class Ingredient3
{
public:
   virtual void exec3() = 0;
};

class Ingredient3_Kind1 : public Ingredient3
{
public:
   Ingredient3_Kind1()
   {
      cout << "Ingredient3_Kind1 constructor...\n";
   }

   void exec3()
   {
      cout << "Executing: Ingredient3_Kind1\n";
   }
};

class Ingredient3_Kind2 : public Ingredient3
{
public:
   Ingredient3_Kind2()
   {
      cout << "Ingredient3_Kind2 constructor...\n";
   }

   void exec3()
   {
      cout << "Executing: Ingredient3_Kind2\n";
   }
};


//----------------------------------------------------------------------
//  
//----------------------------------------------------------------------

class Final_Product
{
public:
   Ingredient1* ingredient1;
   Ingredient2* ingredient2;
   Ingredient3* ingredient3;

   void show_final_product()
   {
      ingredient1->exec1();
      ingredient2->exec2();
      ingredient3->exec3();
   }
};


//----------------------------------------------------------------------
//  
//----------------------------------------------------------------------

class Builder
{
public:
   virtual Ingredient1* new_Ingredient1() = 0;
   virtual Ingredient2* new_Ingredient2() = 0;
   virtual Ingredient3* new_Ingredient3() = 0;
};


//----------------------------------------------------------------------
//  
//----------------------------------------------------------------------

class Product1 : public Builder
{
public:
   Ingredient1* new_Ingredient1()
   {
      Ingredient1* ingredient1 = new Ingredient1_Kind1;
      return ingredient1;
   }

   Ingredient2* new_Ingredient2()
   {
      Ingredient2* ingredient2 = new Ingredient2_Kind1;
      return ingredient2;
   }

   Ingredient3* new_Ingredient3()
   {
      Ingredient3* ingredient3 = new Ingredient3_Kind1;
      return ingredient3;
   }
};


//----------------------------------------------------------------------
//  
//----------------------------------------------------------------------

class Director
{
public:
   Builder* builder;

   void new_Builder( Builder* b )
   {
      builder = b;
   }

   Final_Product* new_FinalProduct()
   {
      Final_Product* final_product = new Final_Product;

      final_product->ingredient1 = builder->new_Ingredient1();
      final_product->ingredient2 = builder->new_Ingredient2();
      final_product->ingredient3 = builder->new_Ingredient3();

      return final_product;
   }
};


//----------------------------------------------------------------------
//  
//----------------------------------------------------------------------

int main()
{

   cout << "\nA final product built with director and ingredients of one kind:\n";

   Final_Product* final_product1;

   Director director;

   Product1 product1_Builder;

   director.new_Builder( &product1_Builder );

   final_product1 = director.new_FinalProduct();
   final_product1->show_final_product();


   cout << "\nA final product built without director and ingredients of different kind:\n";

   Final_Product final_product2;
   final_product2.ingredient1 = new Ingredient1_Kind2;
   final_product2.ingredient2 = new Ingredient2_Kind2;
   final_product2.ingredient3 = new Ingredient3_Kind2;
   final_product2.show_final_product();

}
