#include <iostream>

       #include <cmath>

        

       const auto Epsilon = 0.00000000001;

       const auto NoLine  = 0;

        

       // return x where line and first circle intersection

       double getIntersection(double slope)

       {

         // circle: (x-1)^2 + (y-1)^2 = 1

         //                   (y-1)^2 = 1 - (x-1)^2

         //                    y-1    = sqrt(1 - (x-1)^2)

         //                         y = 1 - sqrt(1 - (x-1)^2)

         // line:                   y = mx    <= where m is the slope

         // their intersection:    mx = 1 - sqrt(1 - (x-1)^2)

        

         // I entered those formula in Wolfram Alpha and didn't like the output ... so let's solve this numerically !

         // choose any x in 0 < x < 1

         auto x    = 0.5;

         // adjust x by this value if not precise enough

         auto step = 0.1;

        

         while (true)

         {

           // good enough ?

           auto leftSide  = slope * x;

           auto rightSide = 1 - sqrt(1 - (x - 1)*(x - 1)); // see above how I got this formula

           if (fabs(leftSide - rightSide) < Epsilon)

             return x;

        

           // move x

           if (leftSide > rightSide)

             x -= step;

           else

             x += step;

        

           // take smaller steps

           step *= 0.99;

         }

       }

        

       // return area of the L-shaped area

       double getAreaL(double slope)

       {

         // x-coordinate of first intersection between line and circle

         double intersection = 0;

         // area of the triangle on the left side of the intersection

         double leftArea     = 0;

         if (slope > 0)

         {

           intersection = getIntersection(slope);

           leftArea = intersection * (intersection * slope) / 2;

         }

        

         // the area on the right side of the intersection can be computed exactly - but I hate ugly looking formulas and prefer C++ code :-)

        

         // numerically integrate area between intersection and "where the first circle touches the box"

         auto rightArea = 0.0;

         auto Step = (1 - intersection) / 100000;

         for (double x = intersection; x < 1; x += Step)

         {

           double y = 1 - sqrt(1 - (x - 1)*(x - 1)); // same formula as in getIntersection

           rightArea += y * Step;

         }

        

         return leftArea + rightArea;

       }

        

       int main()

       {

         // stop if below 0.1%

         auto limit = 0.1;

         std::cin >> limit;

        

         // a circle has an area of A=pi * r^2

         // r=1 => A = pi

         // the box around the circle has an area of 2^2 = 4

         // there are four L's between circle and box, I only need the one in the lower half

         // L = (4 - pi) / 4 = 0.21460183660255169038433915418012...

         auto L = getAreaL(NoLine);   // NoLine=0 is a special case in getAreaL

        

         auto numCircles = 1;

         auto step = 64; // powers of two are great, but could be any other positive number, too (even 1)

         while (true)

         {

           auto slope = 1.0 / numCircles;

           auto area  = getAreaL(slope);

           // area small enough ?

           auto percentage = 100 * area / L;

           if (percentage < limit)

           {

             // reached small step size, found solution

             if (step == 1)

               break;

        

             // maybe I "jumped over" the correct solution, go back and reduce step size

             numCircles -= step;

             step /= 2;

           }

        

           // look at next slope

           numCircles += step;

         }

        

         // and print the solution

         std::cout << numCircles << std::endl;

         return 0;

       }