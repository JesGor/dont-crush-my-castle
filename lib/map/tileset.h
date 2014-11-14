//TITLE: TILESET_H
//PROJECT: DON´T CRUSH MY CASTLE
//AUTHOR: Andrés Ortiz
//VERSION: 0.2
//DESCRIPTION: Information about a set of tiles to be used on maps
#ifndef TILESET_H
#define TILESET_H


typedef int tile_id; //defines a id for a tile in the tileset
class tileset {
private:
    map<tile_id,tile> tile_list;
    string name;
    unsigned int tile_width; //each tile height and width
    unsigned int tile_height;
    //  const static string tmx_tiletype_property; //defines the name of the property used on tmx for tiletype
public:
    //default constructor
    tileset();
    //contructor from tmx file
    //tileset(const Tmx::Tileset *ts);
    //full constructor
    tileset(const string &name,ALLEGRO_BITMAP *bitmap,const vector<tile_type> &types,unsigned int tile_width,unsigned int tile_height,int ntiles=-1);
    //full constructor (without name)
    tileset(ALLEGRO_BITMAP *bitmap,const vector<tile_type> &types,unsigned int tile_width,unsigned int tile_height,int ntiles=-1);
    ~tileset();
    //ACCESS
    //returns the size of the tileset
    unsigned int size() const;
    //returns tile with given id(null tile if id doesnt match)
    tile get_tile(tile_id id) const;
    //get width of each tile
    unsigned int get_tile_width() const;
    //gets height of each tile
    unsigned int get_tile_height() const;
    //returns name of tileset
    string get_name() const;

    //DRAWING
    //draw the tile with given id in position x,y
    void draw_tile(tile_id id,float x,float y) const;
    //draw the tile with given id in position x,y resizing it into width,height size
    void draw_resized_tile(tile_id id,float x,float y,unsigned int width,unsigned int height) const;
    //resize the tileset, resizing the bitmaps of all tiles in tileset
    void resize_tileset(unsigned int tile_width,unsigned int tile_height);

    //adds a tileset from tmx file to the actual tileset (resizing bitmaps), name and sizes will remain unchanged
    //tiles with same id will not be inserted
    //void add_tmx_tileset(const Tmx::Tileset *ts);
    void destroy_tileset();

private:
    //adds a tile,return true if inserted, false if already exists
    bool add_tile(tile_id id,tile_type type,ALLEGRO_BITMAP *bitmap);
    //slices given bitmap and creates the tileset
    void load_from_bitmap(ALLEGRO_BITMAP *bitmap,const vector<tile_type> &types,unsigned int twidth,unsigned int theight,int ntiles);
    void check() const;
};
#endif