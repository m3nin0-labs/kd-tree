#include "kdtree.hpp"

#include <iostream>

int main()
{
    KDTree kd;

    // Index point geometries
    kd.insert(Point(1997, 11));
    kd.insert(Point(50, 77));
    kd.insert(Point(17, 12));
    kd.insert(Point(10, 12));
    kd.insert(Point(8, 3));
    kd.insert(Point(6, 3));
    kd.insert(Point(1, 3));
    kd.insert(Point(2, 2));
    kd.insert(Point(66, 67));
    kd.insert(Point(1, 4));
    kd.insert(Point(3, 4));
    kd.insert(Point(3, 1));
    kd.insert(Point(3, 2));
    kd.insert(Point(99, 122));
    kd.insert(Point(4, 1));
    kd.insert(Point(1956, 122));
    kd.insert(Point(4, 3));
    kd.insert(Point(6, 2));
    kd.insert(Point(5, 2));

    std::cout << "Searching" << std::endl;
    std::vector<KDNode*>* res = kd.search(Rectangle(2, 5, 0, 4));
    
    std::cout << "Visualizing result" << std::endl;
    std::cout << res->size() << std::endl;
    
    for(KDNode* p: *res)
    {
        std::cout << p->point().x() << " " << p->point().y() << std::endl;
    }

    kd.clear();
    return 0;
}
