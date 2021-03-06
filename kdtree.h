/**
 * @file kdtree.h
 * KDTree implementation using Points in k-dimensional space.
 *
 * @author Zesheng Wang
 * @author Wade Fagen-Ulmschneider
 * @author Cinda Heeren
 * @author Jack Toole
 * @author Sean Massung
 */

#pragma once

#include <vector>
#include "util/coloredout.h"
#include "point.h"

using std::vector;
using std::string;
using std::ostream;
using std::cout;
using std::endl;

/**
 * KDTree class: implemented using Points in Dim dimensional space (given
 * by the template parameter).
 */
template <int Dim>
class KDTree
{
  private:
    /**
     * Internal structure for a node of KDTree.
     * Contains left, right children pointers and a K-dimensional point
     */
    struct KDTreeNode
    {
      Point<Dim> point;
      KDTreeNode *left, *right;

      KDTreeNode() : point(), left(NULL), right(NULL) {}
      KDTreeNode(const Point<Dim> &point) : point(point), left(NULL), right(NULL) {}
    };
   
  public:

    /**
     * Determines if Point a is smaller than Point b in a given dimension d.
     * If there is a tie, break it with Point::operator<().
     *
     * For example:
     *
     *     Point<3> a(1, 2, 3);
     *     Point<3> b(3, 2, 1);
     *     cout << smallerDimVal(a, b, 0) << endl; // should print true
     *     cout << smallerDimVal(a, b, 2) << endl; // should print false
     *     cout << smallerDimVal(a, b, 1) << endl; // based on operator<, this should be true
     *
     * @todo This function is required for MP 5.1.
     * @param first Point to compare.
     * @param second Second point to compare.
     * @param curDim Dimension these points are being compared in.
     * @return A boolean value indicating whether the first Point is smaller
     *  than the second Point in the curDim dimension.
     */
    bool smallerDimVal(const Point<Dim>& first, const Point<Dim>& second,
                       int curDim) const;

    /**
     * Determines if a Point is closer to the target Point than another
     * reference Point. Takes three points: target, currentBest, and
     * potential, and returns whether or not potential is closer to
     * target than currentBest.
     *
     * We are using Euclidean distance to compare k-dimensional
     * points: \f$\sqrt{(p_1-q_1)^2+(p_2-q_2)^2+\ldots+(p_n-q_n)^2} =
     * \sqrt{\sum_{i=1}^n (p_i-q_i)^2}\f$. Note, however, that
     * **minimizing distance is the same as minimizing squared
     * distance**, so you can **avoid invoking the square root** and
     * just compare squared distances in your code.
     *
     * For example:
     *
     *     Point<3> target(1, 3, 5);
     *     Point<3> currentBest1(1, 3, 2);
     *     Point<3> possibleBest1(2, 4, 4);
     *     Point<3> currentBest2(1, 3, 6);
     *     Point<3> possibleBest2(2, 4, 4);
     *     Point<3> currentBest3(0, 2, 4);
     *     Point<3> possibleBest3(2, 4, 6);
     *     cout << shouldReplace(target, currentBest1, possibleBest1) << endl; // true
     *     cout << shouldReplace(target, currentBest2, possibleBest2) << endl; // false
     *     cout << shouldReplace(target, currentBest3, possibleBest3) << endl;
     *      // based on operator<, this should be false
     *
     * @todo This function is required for MP 5.1.
     * @param target The Point we want to be close to.
     * @param currentBest The Point that is currently our closest Point
     *    to target.
     * @param potential Our Point that is a candidate to replace
     *    currentBest (that is, it may be closer to target than
     *    currentBest).
     * @return A boolean value indicating whether potential is closer
     *  to target than currentBest. Ties should be broken with
     *  Point::operator<().
     */
    bool shouldReplace(const Point<Dim>& target, const Point<Dim>& currentBest,
                       const Point<Dim>& potential) const;

    /**
     * Constructs a KDTree from a vector of Points, each having dimension Dim.
     *
     * You need to handle the case that the vector has no Point in it. It should
     * build the tree using recursive helper functions.
     *
     * Since we know the size of the KDTree at construction, we can
     * represent the tree as a linear structure and building the tree nodes
     * based off this structure efficiently. For testing, we **require**
     * the following:
     *
     * 1.  The median node of n nodes is calculated as the cell
     *     \f$\left\lfloor\frac{n-1}{2}\right\rfloor\f$. That is, the
     *     middle node is selected if there are an odd number, and the
     *     item before the middle if there are an even number. **If there
     *     are ties (two points have equal value along a dimension), they
     *     must be decided using Point::operator<().** Although this is
     *     arbitrary and doesn't affect the functionality of the KDTree,
     *     it is required to be able to grade your code.
     *
     * KD-trees are created recursively; at any stage of the construction,
     * the median value in the current dimension is selected and a node is
     * created based on it. Then, all the elements in the current subtree are divided
     * up into elements which are less than the median, or greater than
     * the median, and then the subtrees are created recursively.
     * The children pick the median in the next dimension, and repeat
     * until the entire set of inputs has been processed. Successive
     * levels of the tree split on increasing dimensions, modulo the
     * total number: a 3D tree will have levels split by dimension 0, 1, 2,
     * 0, 1, 2, etc.
     *
     * You will probably want to write a helper function which performs the
     * median selection and partitioning. Maybe you can use a function you
     * already wrote...
     *
     * @see Here is a reference that should help you create concise,
     * efficient code: [Partition-based General Selection
     * Algorithm](http://en.wikipedia.org/wiki/Selection_algorithm). Note
     * that "select pivotIndex between left and right" means that you
     * should choose a midpoint between the left and right indices.
     *
     * @todo This function is required for MP 5.1.
     * @param newPoints The vector of points to build your KDTree off of.
     */
    KDTree(const vector<Point<Dim>>& newPoints);


    /**
     * Copy constructor for KDTree.
     *
     * @param other The KDTree to copy.
     */
    KDTree(const KDTree<Dim>& other);

    /**
     * Assignment operator for KDTree.
     *
     * @param rhs The right hand side of the assignment statement.
     * @return A reference for performing chained assignments.
     */
    KDTree const &operator=(const KDTree<Dim>& rhs);

    /**
     * Destructor for KDTree.
     */
    ~KDTree();

    /**
     * Finds the closest point to the parameter point in the KDTree.
     *
     * This function takes a reference to a template parameter Point and
     * returns the Point closest to it in the tree. We are defining
     * closest here to be the minimum Euclidean distance between elements.
     * Again, **if there are ties (this time in distance), they must be
     * decided using Point::operator<().** Recall that an HSLAPixel is
     * defined by three components: hue, saturation, and luminance.
     *
     * The findNearestNeighbor() search is done in two steps: a search to
     * find the smallest hyperrectangle that contains the target element,
     * and then a back traversal to see if any other hyperrectangle could
     * contain a closer point, which may be a point with smaller distance
     * or a point with equal distance, but a "smaller" point (as defined
     * by operator< in the point class). In the first step, you must
     * recursively traverse down the tree, at each level choosing the
     * subtree which represents the region containing the search element
     * (another place to save some duplicate code?). When you reach the
     * lowest bounding hyperrectangle, then the corresponding node is
     * effectively the "current best" neighbor.
     *
     * However, it may be the case that a better match exists outside of
     * the containing hyperrectangle. At then end of first step of the
     * search, we start traversing back up the kdtree to the parent node.
     * The current best distance defines a radius which contains the
     * nearest neighbor. During the back-traversal (i.e., stepping out of
     * the recursive calls), you must first check if the distance to the
     * parent node is less than the current radius. If so, then that
     * distance now defines the radius, and we replace the "current best"
     * match. Next, it is necessary to check to see if the current
     * splitting plane's distance from search node is within the current
     * radius. If so, then the opposite subtree could contain a closer
     * node, and must also be searched recursively.
     *
     * During the back-traversal, it is important to only check the
     * subtrees that are within the current radius, or else the efficiency
     * of the kdtree is lost. If the distance from the search node to the
     * splitting plane is greater than the current radius, then there
     * cannot possibly be a better nearest neighbor in the subtree, so the
     * subtree can be skipped entirely.
     *
     * You can assume that findNearestNeighbor will only be called on a
     * valid kd-tree.
     *
     * @see Here is a reference we found quite useful in writing our kd-tree:
     *  [Andrew Moore's KD-Tree Tutorial]
     * (https://courses.engr.illinois.edu/cs225/sp2018/private/mps/5/moore-tutorial.pdf).
     *
     * @see There is [an example]
     * (https://courses.engr.illinois.edu/cs225/sp2018/mps/5/) in the MP5 instruction.
     *
     * @todo This function is required for MP 5.1.
     * @param query The point we wish to find the closest neighbor to in the
     *  tree.
     * @return The closest point to a in the KDTree.
     */
    Point<Dim> findNearestNeighbor(const Point<Dim>& query) const;

    // functions used for grading:

    /**
     * You do not need to modify this function. Its implementation is in
     *  kdtree_extras.cpp.
     * Prints the KDTree to the terminal in a pretty way.
     */
    void printTree(ostream& out = cout,
                   colored_out::enable_t enable_bold = colored_out::COUT,
                   int modWidth = -1) const;

  private:

    /** Internal representation, root and size **/
    KDTreeNode *root;
    size_t size;
    vector<Point<Dim>> Points;
    /** Helper function for grading */
    int getPrintData(KDTreeNode * subroot) const;

    /** Helper function for grading */
    void printTree(KDTreeNode * subroot, std::vector<std::string>& output,
                   int left, int top, int width, int currd) const;

    /**
     * @todo Add your helper functions here.
     */
    // KDTreeNode* buildhelper(vector <Point<Dim>> &v, int vleft, int vright, int dimention){
    //     if(vleft == vright){
            

    //         KDTreeNode* subroot = new KDTreeNode(v[vleft]);
    //         return subroot;
    //     }else{
            
    //         int median = (vleft + vright) / 2;
    //         KDTreeNode* subroot = new KDTreeNode(getmedian(v, vleft, vright, median, dimention));
    //         int newvright = (vleft+vright)/2-1 >= vleft ? (vleft+vright)/2-1 : vleft;
    //         int newvleft = (vleft+vright)/2+1 <= vright ? (vleft+vright)/2+1 : vright;
    //         if(median != vleft){
    //             subroot->left = buildhelper(v, vleft, newvright, (dimention+1)%Dim);
    //         }
    //         if(median != vright){
    //             subroot->right = buildhelper(v, newvleft, vright, (dimention+1)%Dim);
    //         }
    //         return subroot;
    //     }     
    // }
    KDTreeNode* treeHelper(vector <Point<Dim>> &v, int vleft, int vright, int dimention){
        
        int tempLeft = vleft;
        int tempRight = vright;

        if(tempLeft != tempRight)
        {
            int average = (tempLeft + tempRight)/2;
            KDTreeNode* subroot = new KDTreeNode(middleHelper(v, tempLeft, tempRight, average, dimention));
            int newvright = (tempLeft+tempRight)/2-1 >= tempLeft ? (tempLeft+tempRight)/2-1 : tempLeft;
            int newvleft = (tempLeft+tempRight)/2+1 <= tempRight ? (tempLeft+tempRight)/2+1 : tempRight;

            if(average != tempRight)
            {
                subroot->right = treeHelper(v, newvleft, tempRight, (dimention+1)%Dim);
            }
            if(average != vleft)
            {
                subroot->left = treeHelper(v, tempLeft, newvright, (dimention+1)%Dim);
            }
            return subroot;
        }
        else
        {
            KDTreeNode* subroot = new KDTreeNode(v[tempLeft]);
            return subroot;
        }     
    }

            // KDTreeNode* subroot = new KDTreeNode(v[vleft]);
            // return subroot;
    // Point<Dim>& getmedian(vector<Point<Dim>> &v, int start_point, int end_point, int median, int dimention){
    //     int parti = partition(v, start_point, end_point, dimention);
    //     if(start_point == end_point){
    //         return v[start_point];
    //     }
    //     if(median < parti){
    //         return getmedian(v, start_point, parti - 1, median, dimention);
    //     }else if(median > parti){
    //         return getmedian(v, parti + 1, end_point, median, dimention);
    //     }else{
    //         return v[parti];
    //     }
    // }

    // int partition(vector <Point<Dim>> &v, int vleft, int vright, int dimention){
    //     if(vleft == vright){
    //         return vleft; 
    //     }
    //     int pivotIndex = int((vleft + vright) / 2);
    //     Point<Dim> temp = v[vright];
    //     v[vright] = v[pivotIndex];
    //     v[pivotIndex] = temp;
    //     int storeIndex = vleft;
    //     for(int i = storeIndex; i < vright; i++){
    //         if(v[i][dimention] < v[vright][dimention] || 
    //         ((v[i][dimention] == v[vright][dimention])&&(v[i]<v[vright]))){
    //             temp = v[storeIndex];
    //             v[storeIndex] = v[i];
    //             v[i] = temp;
    //             storeIndex ++;
    //         }
    //     }
    //     temp = v[storeIndex];
    //     v[storeIndex] = v[vright];
    //     v[vright] = temp;
    //     return storeIndex; 
    // }

    int middleHelper(vector <Point<Dim>> &v, int vleft, int vright, int median, int dimention)
    {
        int tempLeft = vleft;
        int tempRight = vright;
        
        if(tempLeft == tempRight)
        {
            return vleft; 
        }
        
        int Index1 = int((vleft + vright)/2);
        
        Point<Dim> IndexTemp = v[tempRight];
        v[tempRight] = v[Index1];
        v[Index1] = IndexTemp;
        
        int Index2 = tempLeft;
        
        for(int i = Index2; i < tempRight; i++)
        {
            // if(v[i][dimention] < v[tempRight][dimention] || 
            // ((v[i][dimention] == v[tempRight][dimention])&&(v[i]<v[tempRight])))
            // {
            //     temp = v[Index2];
            //     v[Index2] = v[i];
            //     v[i] = temp;
            //     Index2++;
            // }
            if(v[i][dimention] < v[tempRight][dimention])
            {
                IndexTemp = v[Index2];
                v[Index2] = v[i];
                v[i] = IndexTemp;
                Index2++;                
            }
            else if(v[i][dimention] == v[tempRight][dimention])&&(v[i]<v[tempRight])
            {
                IndexTemp = v[Index2];
                v[Index2] = v[i];
                v[i] = IndexTemp;
                Index2++;
            }
        }
        IndexTemp = v[Index2];
        v[Index2] = v[tempRight];
        v[tempRight] = IndexTemp;
        
        int Index3 = Index2;
        if(start_point == end_point)
        {
            return v[start_point];
        }
        if(median < Index3)
        {
            return middleHelper(v, start_point, Index3 - 1, median, dimention);
        }
        else if(median > parti)
        {
            return middleHelper(v, Index3 + 1, end_point, median, dimention);
        }
        else
        {
            return v[Index3];
        }
    }

    void _copy(KDTreeNode* &subroot, KDTreeNode* otherroot){

        if(otherroot == NULL){
            return;
        }
        subroot = new KDTreeNode(otherroot->point);
        _copy(subroot->left, otherroot->left);
        _copy(subroot->right, otherroot->right);
    }

    void _destory(KDTreeNode* subroot){

        if(subroot == NULL){
            return;
        }else{
            _destory(subroot -> left);
            _destory(subroot -> right);
            delete subroot;
            subroot = NULL;
        }
    }

    Point<Dim> findhelper( int dimention, int left, int right, 
        const Point<Dim> &find_best_, const Point<Dim> &query) const
    {
        int average = (left + right)/2;
        bool to_left = false;
        Point<Dim> find_best = find_best_;
        if(left == right)
        {
            if(shouldReplace(query, find_best, Points[left]))
            {
                find_best = Points[left];
            }
            
            return find_best;
        }
        else if (smallerDimVal(query, Points[median], dimention))
        {
            if(left < median)
            {
                find_best = findhelper((dimention+1)%Dim, left, median - 1, find_best, query);
                to_left = true;
            }
            else if(median < right)
            {
                find_best = findhelper((dimention+1)%Dim, median+1, right, find_best, query);
                to_left = false;
            }
        }
        else
        {
            if(median < right)
            {
                find_best = findhelper((dimention+1)%Dim, median+1, right, find_best, query);
            }
            else if(left < median)
            {
                find_best = findhelper((dimention+1)%Dim, left, median - 1, find_best, query);
                to_left = true;
            }
        }

        if(shouldReplace(query, find_best, Points[median]))
        {
            find_best = Points[median];
        }

        double bestdistance = 0;
        double judge = 0;
        for(int i = 0; i < Dim; i ++)
        {
            bestdistance += (find_best[i] - query[i])*(find_best[i] - query[i]);
        }
        
        judge = (Points[median][dimention] - query[dimention])*(Points[median][dimention] - query[dimention]);
        
        if(judge <= bestdistance)
        {
            if(median < right && to_left)
            {
                find_best = findhelper((dimention+1)%Dim, median+1, right, find_best, query);
            }
            else if(left < median && !to_left)
            {
                find_best = findhelper((dimention+1)%Dim, left, median-1, find_best, query);
            }
        }
    
        return find_best;
    }
};

#include "kdtree.hpp"
#include "kdtree_extras.hpp"