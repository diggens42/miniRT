// main struct for calculations
// left handed coord-system
// x -> right, y -> up, z -> away from you, w = 0 -> vector, w = 1 -> point (could be bool idk?)
// points are positions in space, vectors represent direction + distance
typedef struct s_tuple {
	double x;
	double y;
	double z;
	double w; 
}	t_tuple;