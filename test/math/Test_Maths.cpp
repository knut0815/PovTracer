#include "math/Maths.hpp"
#include <catch/catch.hpp>
TEST_CASE("Projection1","[Vectors]")
{
   Vector3 a(1,0,0);
   Vector3 b(2,1,0);
   Vector3 a1 = Maths::project(b,a);
   REQUIRE(a1.x() == 2.0);
   REQUIRE(a1.y() == 0);
   REQUIRE(a1.z() == 0);
   


}
TEST_CASE("Projection2","[Vectors]")
{
   Vector3 a(1,0,0);
   Vector3 b(0,1,0);
   Vector3 a1 = Maths::project(b,a);
   REQUIRE(a1.x() == 0.0);
   REQUIRE(a1.y() == 0);
   REQUIRE(a1.z() == 0);
   
   

}
TEST_CASE("Projection3","[Vectors]")
{
   Vector3 a(1,0,0);
   Vector3 b(1,0,0);
   Vector3 a1 = Maths::project(b,a);
   REQUIRE(a1.x() == 1.0);
   REQUIRE(a1.y() == 0);
   REQUIRE(a1.z() == 0);
   
   

}
TEST_CASE("Map", "[Mapping]")
{
   REQUIRE(Maths::map(0,1,0,100,0.5) == 50);
   REQUIRE(Maths::map(0,640,-0.5,0.5,320) == 0);
   REQUIRE(Maths::map(0,1,1,2,0.5) == 1.5);
   
}

TEST_CASE("Refract 1", "[Refraction]")
{
   //Through no issue IOR
   Vector3 entry(1,1,1);
   Vector3 nor(0,-1,0);
   Vector3 exitVec = Maths::refract(1,1,entry,nor);
   REQUIRE((exitVec - entry.normalized()).norm() < kEpsilon);
}

TEST_CASE("Sample 1", "[Sample]")
{
   for(int i = 0; i < 128; i++)
   {
      Vector3 test = Maths::generateHemisphereSample(Vector3(0,0,1),2);
      REQUIRE(test.z() >= 0);
   }
}
TEST_CASE("Sample 2", "[Sample]")
{
   for(int i = 0; i < 128; i++)
   {
      Vector3 test = Maths::generateHemisphereSample(Vector3(0,0,-1),2);
      REQUIRE(test.z() <= 0);
   }
}
TEST_CASE("Sample 3", "[Sample]")
{
   for(int i = 0; i < 128; i++)
   {
      Vector3 test = Maths::generateHemisphereSample(Vector3(1,0,0),2);
      REQUIRE(test.x() >= 0);
   }
}
TEST_CASE("Sample 4", "[Sample]")
{
   for(int i = 0; i < 128; i++)
   {
      Vector3 test = Maths::generateHemisphereSample(Vector3(-1,0,0),2);
      REQUIRE(test.x() <= 0);
   }
}
TEST_CASE("Sample 5", "[Sample]")
{
   for(int i = 0; i < 128; i++)
   {
      Vector3 test = Maths::generateHemisphereSample(Vector3(0,1,0),2);
      REQUIRE(test.y() >= 0);
   }
}
TEST_CASE("Sample 6", "[Sample]")
{
   for(int i = 0; i < 128; i++)
   {
      Vector3 test = Maths::generateHemisphereSample(Vector3(0,-1,0),2);
      REQUIRE(test.y() <= 0);
   }
}