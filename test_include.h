#include <cstring>
#include <iostream>
#include "concave_polygon.h"


std::vector<std::vector<cxd::Vec2>> wrapper(std::vector<int[2]> s)
{
    	// Create a vector of vertices
    std::vector<cxd::Vertex > vertices;

    for (auto i: s) { 
        vertices.push_back(
            cxd::Vec2({ (double)i[0], (double)i[1] })
            );  
    }

    // Create polygon from these vertices
    cxd::ConcavePolygon concavePoly(vertices);

    // Perform convex decomposition on polygon
    concavePoly.convexDecomp();

    // Retrieve a decomposed convex subpolygon by index
    // We still use the concave poly type here
    cxd::ConcavePolygon subPolygon = concavePoly.getSubPolygon(0);

    // Retrieve vertices from the subpolygon (also applies to the
    // concave polygon we defined earlier)
    std::vector<cxd::Vertex > subPolyVerts = subPolygon.getVertices();

    // Create a vector and retrieve all convex subpolygons
    // as a single list
    std::vector<cxd::ConcavePolygon > subPolygonList;
    concavePoly.returnLowestLevelPolys(subPolygonList);
    std::vector<std::vector<cxd::Vec2>> subPolygonVec;
    for (auto sub: subPolygonList)
    {
        std::vector<cxd::Vec2> v;
        for (auto s: sub.getVertices())
        {
            v.push_back(s.position);
        }
        subPolygonVec.push_back(v);
    }
    return subPolygonVec;
}

