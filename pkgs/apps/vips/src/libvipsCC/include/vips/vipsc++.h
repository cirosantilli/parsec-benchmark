
// headers for package arithmetic
// this file automatically generated from
// VIPS library 7.22.1-Tue Jun 22 10:26:51 BST 2010
VImage abs();
VImage acos();
VImage add( VImage );
VImage asin();
VImage atan();
double avg();
double point_bilinear( double, double, int );
VImage bandmean();
VImage ceil();
VImage cos();
VImage cross_phase( VImage );
double deviate();
VImage divide( VImage );
VImage exp10();
VImage expn( double );
VImage expn( std::vector<double> );
VImage exp();
VImage floor();
VImage invert();
VImage lin( double, double );
static VImage linreg( std::vector<VImage>, std::vector<double> );
VImage lin( std::vector<double>, std::vector<double> );
VImage log10();
VImage log();
double max();
std::complex<double> maxpos();
double maxpos_avg( double&, double& );
VDMask measure( int, int, int, int, int, int );
double min();
std::complex<double> minpos();
VImage multiply( VImage );
VImage pow( double );
VImage pow( std::vector<double> );
VImage recomb( VDMask );
VImage remainder( VImage );
VImage remainder( double );
VImage remainder( std::vector<double> );
VImage rint();
VImage sign();
VImage sin();
VDMask stats();
VImage subtract( VImage );
VImage tan();

// headers for package boolean
// this file automatically generated from
// VIPS library 7.22.1-Tue Jun 22 10:26:51 BST 2010
VImage andimage( VImage );
VImage andimage( int );
VImage andimage( std::vector<double> );
VImage orimage( VImage );
VImage orimage( int );
VImage orimage( std::vector<double> );
VImage eorimage( VImage );
VImage eorimage( int );
VImage eorimage( std::vector<double> );
VImage shiftleft( std::vector<double> );
VImage shiftleft( int );
VImage shiftright( std::vector<double> );
VImage shiftright( int );

// headers for package cimg
// this file automatically generated from
// VIPS library 7.22.1-Tue Jun 22 10:26:51 BST 2010
VImage greyc( int, double, double, double, double, double, double, double, double, int, int );
VImage greyc_mask( VImage, int, double, double, double, double, double, double, double, double, int, int );

// headers for package colour
// this file automatically generated from
// VIPS library 7.22.1-Tue Jun 22 10:26:51 BST 2010
VImage LCh2Lab();
VImage LCh2UCS();
VImage Lab2LCh();
VImage Lab2LabQ();
VImage Lab2LabS();
VImage Lab2UCS();
VImage Lab2XYZ();
VImage Lab2XYZ_temp( double, double, double );
VImage Lab2disp( VDisplay );
VImage LabQ2LabS();
VImage LabQ2Lab();
VImage LabQ2XYZ();
VImage LabQ2disp( VDisplay );
VImage LabS2LabQ();
VImage LabS2Lab();
VImage UCS2LCh();
VImage UCS2Lab();
VImage UCS2XYZ();
VImage XYZ2Lab();
VImage XYZ2Lab_temp( double, double, double );
VImage XYZ2UCS();
VImage XYZ2Yxy();
VImage XYZ2disp( VDisplay );
VImage XYZ2sRGB();
VImage Yxy2XYZ();
VImage dE00_fromLab( VImage );
VImage dECMC_fromLab( VImage );
VImage dECMC_fromdisp( VImage, VDisplay );
VImage dE_fromLab( VImage );
VImage dE_fromXYZ( VImage );
VImage dE_fromdisp( VImage, VDisplay );
VImage disp2Lab( VDisplay );
VImage disp2XYZ( VDisplay );
VImage float2rad();
VImage icc_ac2rc( char* );
VImage icc_export_depth( int, char*, int );
VImage icc_import( char*, int );
VImage icc_import_embedded( int );
VImage icc_transform( char*, char*, int );
VImage lab_morph( VDMask, double, double, double, double );
VImage rad2float();
VImage sRGB2XYZ();

// headers for package conversion
// this file automatically generated from
// VIPS library 7.22.1-Tue Jun 22 10:26:51 BST 2010
static VImage gaussnoise( int, int, double, double );
VImage bandjoin( VImage );
static VImage black( int, int, int );
VImage c2amph();
VImage c2imag();
VImage c2real();
VImage c2rect();
VImage clip2fmt( int );
VImage copy();
VImage copy_file();
VImage copy_morph( int, int, int );
VImage copy_swap();
VImage copy_set( int, double, double, int, int );
VImage extract_area( int, int, int, int );
VImage extract_areabands( int, int, int, int, int, int );
VImage extract_band( int );
VImage extract_bands( int, int );
VImage extract( int, int, int, int, int );
VImage falsecolour();
VImage fliphor();
VImage flipver();
static VImage gbandjoin( std::vector<VImage> );
VImage grid( int, int, int );
VImage insert( VImage, int, int );
VImage insert( VImage, std::vector<int>, std::vector<int> );
VImage insert_noexpand( VImage, int, int );
VImage embed( int, int, int, int, int );
VImage lrjoin( VImage );
static VImage mask2vips( VDMask );
VImage msb();
VImage msb_band( int );
VImage replicate( int, int );
VImage ri2c( VImage );
VImage rot180();
VImage rot270();
VImage rot90();
VImage scale();
VImage scaleps();
VImage subsample( int, int );
char* system( char* );
VImage system_image( char*, char*, char*, char*& );
VImage tbjoin( VImage );
static VImage text( char*, char*, int, int, int );
VDMask vips2mask();
VImage wrap( int, int );
VImage zoom( int, int );

// headers for package convolution
// this file automatically generated from
// VIPS library 7.22.1-Tue Jun 22 10:26:51 BST 2010
VImage addgnoise( double );
VImage compass( VIMask );
VImage contrast_surface( int, int );
VImage conv( VIMask );
VImage conv( VDMask );
VImage convsep( VIMask );
VImage convsep( VDMask );
VImage fastcor( VImage );
VImage gradcor( VImage );
VImage gradient( VIMask );
VImage grad_x();
VImage grad_y();
VImage lindetect( VIMask );
VImage sharpen( int, double, double, double, double, double );
VImage spcor( VImage );

// headers for package deprecated
// this file automatically generated from
// VIPS library 7.22.1-Tue Jun 22 10:26:51 BST 2010
VImage clip();
VImage c2ps();
VImage resize_linear( int, int );
VImage cmulnorm( VImage );
VImage fav4( VImage, VImage, VImage );
VImage gadd( double, double, VImage, double );
VImage icc_export( char*, int );
VImage litecor( VImage, int, double );
VImage affine( double, double, double, double, double, double, int, int, int, int );
VImage clip2c();
VImage clip2cm();
VImage clip2d();
VImage clip2dcm();
VImage clip2f();
VImage clip2i();
VImage convsub( VIMask, int, int );
VImage convf( VDMask );
VImage convsepf( VDMask );
VImage clip2s();
VImage clip2ui();
VImage insertplace( VImage, std::vector<int>, std::vector<int> );
VImage clip2us();
VImage slice( double, double );
VImage segment( int& );
void line( int, int, int, int, int );
VImage thresh( double );
VImage convf_raw( VDMask );
VImage conv_raw( VIMask );
VImage contrast_surface_raw( int, int );
VImage convsepf_raw( VDMask );
VImage convsep_raw( VIMask );
VImage fastcor_raw( VImage );
VImage gradcor_raw( VImage );
VImage spcor_raw( VImage );
VImage lhisteq_raw( int, int );
VImage stdif_raw( double, double, double, double, int, int );
VImage rank_raw( int, int, int );
VImage dilate_raw( VIMask );
VImage erode_raw( VIMask );
VImage similarity_area( double, double, double, double, int, int, int, int );
VImage similarity( double, double, double, double );

// headers for package format
// this file automatically generated from
// VIPS library 7.22.1-Tue Jun 22 10:26:51 BST 2010
static VImage csv2vips( char* );
static VImage jpeg2vips( char* );
static VImage magick2vips( char* );
static VImage png2vips( char* );
static VImage exr2vips( char* );
static VImage ppm2vips( char* );
static VImage analyze2vips( char* );
static VImage tiff2vips( char* );
void vips2csv( char* );
void vips2jpeg( char* );
void vips2mimejpeg( int );
void vips2png( char* );
void vips2ppm( char* );
void vips2tiff( char* );

// headers for package freq_filt
// this file automatically generated from
// VIPS library 7.22.1-Tue Jun 22 10:26:51 BST 2010
static VImage create_fmask( int, int, int, double, double, double, double, double );
VImage disp_ps();
VImage flt_image_freq( int, double, double, double, double, double );
static VImage fractsurf( int, double );
VImage freqflt( VImage );
VImage fwfft();
VImage rotquad();
VImage invfft();
VImage phasecor_fft( VImage );
VImage invfftr();

// headers for package histograms_lut
// this file automatically generated from
// VIPS library 7.22.1-Tue Jun 22 10:26:51 BST 2010
VImage gammacorrect( double );
VImage heq( int );
VImage hist( int );
VImage histcum();
VImage histeq();
VImage hist_indexed( VImage );
VImage histgr( int );
VImage histnD( int );
VImage histnorm();
VImage histplot();
VImage histspec( VImage );
VImage hsp( VImage );
static VImage identity( int );
static VImage identity_ushort( int, int );
int ismonotonic();
VImage lhisteq( int, int );
int mpercent( double );
static VImage invertlut( VDMask, int );
static VImage buildlut( VDMask );
VImage maplut( VImage );
VImage project( VImage& );
VImage stdif( double, double, double, double, int, int );
VImage tone_analyse( double, double, double, double, double, double );
static VImage tone_build( double, double, double, double, double, double, double, double );
static VImage tone_build_range( int, int, double, double, double, double, double, double, double, double );
VImage tone_map( VImage );

// headers for package inplace
// this file automatically generated from
// VIPS library 7.22.1-Tue Jun 22 10:26:51 BST 2010
void circle( int, int, int, int );
VImage flood_copy( int, int, std::vector<double> );
VImage flood_blob_copy( int, int, std::vector<double> );
VImage flood_other_copy( VImage, int, int, int );
void insertplace( VImage, int, int );
VImage line( VImage, VImage, std::vector<int>, std::vector<int>, std::vector<int>, std::vector<int> );

// headers for package iofuncs
// this file automatically generated from
// VIPS library 7.22.1-Tue Jun 22 10:26:51 BST 2010
static VImage binfile( char*, int, int, int, int );
VImage cache( int, int, int );
char* getext();
int header_get_typeof( char* );
int header_int( char* );
double header_double( char* );
char* header_string( char* );
char* history_get();
void printdesc();

// headers for package mask
// this file automatically generated from
// VIPS library 7.22.1-Tue Jun 22 10:26:51 BST 2010

// headers for package morphology
// this file automatically generated from
// VIPS library 7.22.1-Tue Jun 22 10:26:51 BST 2010
double cntlines( int );
VImage dilate( VIMask );
VImage rank( int, int, int );
static VImage rank_image( std::vector<VImage>, int );
static VImage maxvalue( std::vector<VImage> );
VImage label_regions( int& );
VImage zerox( int );
VImage erode( VIMask );
VImage profile( int );

// headers for package mosaicing
// this file automatically generated from
// VIPS library 7.22.1-Tue Jun 22 10:26:51 BST 2010
VImage align_bands();
double correl( VImage, int, int, int, int, int, int, int&, int& );
int _find_lroverlap( VImage, int, int, int, int, int, int, int, int&, double&, double&, double&, double& );
int _find_tboverlap( VImage, int, int, int, int, int, int, int, int&, double&, double&, double&, double& );
VImage global_balance( double );
VImage global_balancef( double );
VImage lrmerge( VImage, int, int, int );
VImage lrmerge1( VImage, int, int, int, int, int, int, int, int, int );
VImage lrmosaic( VImage, int, int, int, int, int, int, int, int, int );
VImage lrmosaic1( VImage, int, int, int, int, int, int, int, int, int, int, int, int, int );
VImage match_linear( VImage, int, int, int, int, int, int, int, int );
VImage match_linear_search( VImage, int, int, int, int, int, int, int, int, int, int );
double maxpos_subpel( double& );
VImage remosaic( char*, char* );
VImage tbmerge( VImage, int, int, int );
VImage tbmerge1( VImage, int, int, int, int, int, int, int, int, int );
VImage tbmosaic( VImage, int, int, int, int, int, int, int, int, int );
VImage tbmosaic1( VImage, int, int, int, int, int, int, int, int, int, int, int, int, int );

// headers for package other
// this file automatically generated from
// VIPS library 7.22.1-Tue Jun 22 10:26:51 BST 2010
VImage benchmark();
double benchmark2();
VImage benchmarkn( int );
static VImage eye( int, int, double );
static VImage grey( int, int );
static VImage feye( int, int, double );
static VImage fgrey( int, int );
static VImage fzone( int );
static VImage make_xy( int, int );
static VImage zone( int );

// headers for package relational
// this file automatically generated from
// VIPS library 7.22.1-Tue Jun 22 10:26:51 BST 2010
VImage blend( VImage, VImage );
VImage equal( VImage );
VImage equal( std::vector<double> );
VImage equal( double );
VImage ifthenelse( VImage, VImage );
VImage less( VImage );
VImage less( std::vector<double> );
VImage less( double );
VImage lesseq( VImage );
VImage lesseq( std::vector<double> );
VImage lesseq( double );
VImage more( VImage );
VImage more( std::vector<double> );
VImage more( double );
VImage moreeq( VImage );
VImage moreeq( std::vector<double> );
VImage moreeq( double );
VImage notequal( VImage );
VImage notequal( std::vector<double> );
VImage notequal( double );

// headers for package resample
// this file automatically generated from
// VIPS library 7.22.1-Tue Jun 22 10:26:51 BST 2010
VImage rightshift_size( int, int, int );
VImage shrink( double, double );
VImage stretch3( double, double );

// headers for package video
// this file automatically generated from
// VIPS library 7.22.1-Tue Jun 22 10:26:51 BST 2010
static VImage video_test( int, int );
static VImage video_v4l1( char*, int, int, int, int, int, int );

