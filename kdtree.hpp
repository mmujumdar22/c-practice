
/**
 * @file kdtree.cpp
 * Implementation of KDTree class.
 */

#include <utility>
#include <algorithm>

using namespace std;

template <int Dim>
bool KDTree<Dim>::smallerDimVal(const Point<Dim>& first,
                                const Point<Dim>& second, int curDim) const
{
    /**
     * @todo Implement this function!
     */
    bool flag = 0;

    if(first < second)
        flag = 1;

    if(first[curDim] == second[curDim])
        return flag;
    else if(first[curDim] < second[curDim])
        return true;

    return false;

}

template <int Dim>
bool KDTree<Dim>::shouldReplace(const Point<Dim>& target,
                                const Point<Dim>& currentBest,
                                const Point<Dim>& potential) const
{
    /**
     * @todo Implement this function!
     */
    bool flag = 0;

    if(first < second)
        flag = 1;

    double curDistance = 0;
    double potentialDistance = 0;

    for(int i = 0; i < Dim; i++)
    {
        curDistance = curDistance + target[i]*target[i];
        curDistance = curDistance + currentBest[i];
        curDistance = curDistance - target[i]*currentBest[i];

        potentialDistance = potentialDistance + potential[i];
        potentialDistance = potentialDistance + target[i]*target[i];
        potentialDistance = potentialDistance - target[i]*potential[i];
    }    

    if(cur_distance == pot_distance)
        return flag;
    else if(potentialDistance < curDistance)
        return true;

    return false;


}

template <int Dim>
KDTree<Dim>::KDTree(const vector<Point<Dim>>& newPoints)
{
    /**
     * @todo Implement this function!
     */
    
    if(newPoints.size() == 0){
        root = new KDTreeNode();
    }else{
        Points.assign(newPoints.begin(), newPoints.end());
        root = buildhelper(Points, 0, Points.size()-1, 0);
    }
}

template <int Dim>
KDTree<Dim>::KDTree(const KDTree<Dim>& other) {
    /**
     * @todo Implement this function!
     */
    this->Points = other.Points;
    _copy(this->root, other.root);
}

template <int Dim>
const KDTree<Dim>& KDTree<Dim>::operator=(const KDTree<Dim>& rhs) {
    /**
     * @todo Implement this function!
     */
    _destory(this->root);
    _copy(this->root, rhs.root);
    return *this;
}

template <int Dim>
KDTree<Dim>::~KDTree() {
    /**
     * @todo Implement this function!
     */
    _destory(this->root);
}
template <int Dim>
Point<Dim> KDTree<Dim>::findNearestNeighbor(const Point<Dim>& query) const
{
    /**
     * @todo Implement this function!
     */
    
    return findhelper( 0, 0, Points.size()-1, Points[(Points.size()-1)/2], query);
}
