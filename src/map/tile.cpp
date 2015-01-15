//TITLE: TILE_CPP
//PROJECT: DON´T CRUSH MY CASTLE
//AUTHOR: Andrés Ortiz
//VERSION: 0.3
//DESCRIPTION: Defines one tile of a tileset

#include "tile.h"

tile::tile() {
    type=null_tile;
}
tile::tile(tile_type type,ALLEGRO_BITMAP *bitmap) {
    this->type=type;
    unsigned int w=al_get_bitmap_width(bitmap);
    unsigned int h=al_get_bitmap_height(bitmap);
    if(w==0 || h==0) debug_log::report("error,bitmap with size=0",err,true,true,false);
    else {
        this->bitmap=bitmap;
        if(w!=h) {
            debug_log::report("bitmap not squared, resizing to lowest size",warning,true,false,false);
            if(w>h) resize(h);
            else resize(w);
        }
    }
}
tile::tile(tile_type type,ALLEGRO_BITMAP *bitmap,unsigned int side_size) {
    this->type=type;
    unsigned int w=al_get_bitmap_width(bitmap);
    unsigned int h=al_get_bitmap_height(bitmap);
    if(w==0 || h==0) debug_log::report("error,bitmap with size=0",err,true,true,false);
    else {
        this->bitmap=bitmap;
        if(w!=h)  debug_log::report("bitmap not squared",warning,true,false,false);
        resize(side_size);
    }
}

//MODIFICATION
void tile::resize(unsigned int width) {
    if(width==0) debug_log::report("resize bitmap error (size equals 0)",err,true,true,false);
    else {
        resize_bitmap(bitmap,width,width);
    }
}

//Drawing methods
void tile::draw(float x,float y) const {
    al_draw_bitmap(bitmap,x,y,0);
}
void tile::draw_resized(float x,float y,unsigned int width) const {
    if(width==0) debug_log::report("tile size=0",err,true,true,false);
    else
        al_draw_scaled_bitmap(bitmap,0.0,0.0,al_get_bitmap_width(bitmap),al_get_bitmap_height(bitmap),x,y,width,width,0);
}

void tile::destroy_bitmap() {
    al_destroy_bitmap(bitmap);
    type=null_tile;
}

unsigned int tile::get_size() const {
    return al_get_bitmap_width(bitmap);
}

bool tile::check() const {
    bool b=true;
    if(bitmap==NULL && type!=null_tile) {
        debug_log::report("tile with no bitmap",err,true,true,false);
        b=false;
    }
    else if(get_size() != (unsigned int) al_get_bitmap_height(bitmap)) {
        debug_log::report("tile not squared",err,true,true,false);
        b=false;
    }
    return b;
}