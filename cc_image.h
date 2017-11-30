#ifndef CC_IMAGE_H
#define CC_IMAGE_H

class cc_image : public binary_image{
public:
    cc_image(Image i);
    // void print();
    
private:
    int _ncc;
    void connectize();
    void _DFS_Util(int i, int j, int label, int**&);
    std::vector<std::pair<int, int> > _get_neighbors(int i, int j);
    int get_ncc() const;
    friend std::ostream& operator<<(std::ostream& os, const cc_image& cc_i);
};

#endif