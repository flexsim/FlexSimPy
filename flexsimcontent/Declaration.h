// The following license applies to all parts of this file.
/*************************************************
The MIT License

Copyright (c) <2008> <flexsim-dll-project contributors>

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*************************************************/

#ifndef DECLARATION_H
#define DECLARATION_H
//#define P_AP_M

namespace FlexSim {

int bindflexsimfunctions();

/*** FLEXSIM FUNCTIONS ***/
visible int _executefsfile(const char*, int direct);
visible Variant _inheritcode(CallPoint* callpoint);
visible int _mpd(int m);
visible int _mpf(double m);
visible int _mpr();
visible int _mpt(const char* m);
#if FLEXSIM_TARGET_VERSION >= 710
visible int _partype(int index, CallPoint* callpoint);
#endif
visible double _parval(int index, CallPoint* callpoint);
visible TreeNode* _parnode(int index, CallPoint* callpoint);
visible const char* __parstr(int index, CallPoint* callpoint);
visible Variant _param(int index, CallPoint* callpoint);
visible int activateview(treenode xx);
visible Window activeview();
visible Window activedocumentview();
visible int addcommand(treenode node, char* name = (char*)"", char* desc = (char*)"", char* par = (char*)"", char* examp = (char*)"", char* cppsuffix = (char*)"", int returntype = RETURN_TYPE_NUMBER);
visible int addfullhistorymoverecord(unsigned int _id, double _time, TreeNode* _origin, TreeNode* _destination, double _itemtype);
visible double addkinematic(treenode infonode, double _x, double _y, double _z,
	double maxspeed, double acc = 0, double dec = 0,
	double  _startspeed = 0.0, double  _endspeed = 0.0, double  _starttime = -1.0, unsigned short type = KINEMATIC_TRAVEL);
visible treenode addlabel(treenode object, const char* labelname, double value = 0);
visible treenode addtablecol(treenode table, int column = 0, int datatype = 0);
visible treenode addtablerow(treenode table, int row = 0, int datatype = 0);
visible void addtoeventtypelegend(int index, int parameter, int value, const char* legendname);
engine_export void addtoeventtypelegend(const char* name, int parameter, int value, const char* legendname);
visible double addviewtext(treenode target, const char*);
visible int aggregateundorecords(TreeNode* view, const char* description, int id1, int id2, int id3, int id4, int id5, int id6, int id7, int id8);
visible double applyeditstonode(treenode view, treenode obj);
visible int applylinks(treenode view, int reverse = 0);
visible int applyshapefactors(treenode);
visible double applytoedits(treenode view, treenode obj);
visible TreeNode* assertattribute(TreeNode* object, const char* name, int datatype);
visible TreeNode* assertlabel(TreeNode* object, const char* name, int datatype = 0);
visible TreeNode* assertsubnode(TreeNode* node, const char* name, int datatype = 0);
visible TreeNode* assertvariable(TreeNode* object, const char* name, int datatype = 0);
visible treenode attlink(treenode N, const char* s);
visible int autoloadimages();
visible int autoloadshapes();
visible int autoloadsounds();
visible int aviadd(treenode winnode);
visible int avifinish(treenode winnode);
visible int avistart(char* s, treenode winnode, double fps, double uc);
visible char* bbgetbuffer(TreeNode* node);
visible int bbgetsize(TreeNode* node);
visible int bbsetsize(TreeNode* node, int size);
visible int beginaggregatedundo(TreeNode* view, const char* description);
visible void beginignoreundo();
visible double bernoulli(double prob, double a, double b, int stream = 0); // not in LK
visible double beta(double a, double b, double shape1, double shape2, int stream = 0);
visible void bindobjectclassvariable(TreeNode* object, TreeNode** binder, char* variablename, char* classname);
visible int bindtexture(int textureid);
visible double binomial(int t, double p, int stream = 0);
visible int bitwiseand(int, int);
visible int bitwisenot(int);
visible int bitwiseor(int, int);
visible double buildall();
visible double buildnodeflexscript(treenode node);
visible int calculate6DOFrobotinversekinematics(double* loc, treenode planningItem, double* rotOffset,
	double approachOffset, treenode robot, double* d, double* a, double xtrans, double* returnval);
visible double calculateconfidence(double stddev, double nrofdatapoints, double confidence);
visible double cauchy(double locate, double scale, int stream = 0);
visible const char* cdir_cstr();
visible double cempirical(char* tablename, int stream = 0);
visible TreeNode* centerobject(TreeNode*, int);
visible int changedisplay(int width, int height, int depth, int fullscreen, int test);
visible int checkdllconnection(treenode node, int makeconnection);
visible int checkoutmodulefeature(DllModule moduleid, char* feature, char* version);
visible treenode classobject(treenode);
visible int clearbundle(treenode x, int resetflags = 0);
visible int clearconsole();
visible int clearcontents(TreeNode*);
visible double clearglobaltable(char* globaltablename);
engine_export double clearglobaltable(treenode table);
engine_export double clearglobaltable(int globaltablerank);
visible double clickcode();
visible double clientclose(int sock);
visible double clientconnect(int skt, char* hostname, int port);
visible double clientcreate();
visible double clientreceive(int skt, char* Buf, int BufSize, int NoBlock);
visible double clientsend(int skt, char* Msg, int len = 0);
visible int closeallip(TreeNode*);
visible int closeallop(TreeNode*);
visible double closeinput(TreeNode* object);
visible double closeip(TreeNode* node, int index);
visible double closeop(TreeNode* node, int index);
visible double closeoutput(TreeNode* object);
visible int closeview(treenode xx);
visible double cm(double val);
visible double cmdcompile();
visible double cmddelete();
visible double cmdexit();
visible double cmdloadbyextension(const char* thename, int silent);
visible double cmdloadsession(const char* thename);
visible double cmdloadtree(treenode thenode, const char* thename, int nobuild);
visible double cmdnew();
visible double cmdopen();
visible double cmdsaveas();
visible double cmdsavesession(const char* thename);
visible double cmdsavetree(treenode thenode, const char* thename);
visible int codetotemplate(treenode thecode, treenode theedit);
visible char* codetotemplatetext_cstr(treenode thecode);
visible double coloraqua(treenode involved);
visible double colorarray(treenode involved, double val);
engine_export void colorarray(int val, double* colordest);
visible double colorblack(treenode involved);
visible double colorblue(treenode involved);
visible double colorbrown(treenode involved);
visible double colorgray(treenode involved);
visible double colorgreen(treenode involved);
visible double colorlightblue(treenode involved);
visible double colorlime(treenode involved);
visible double colororange(treenode involved);
visible double colorpink(treenode involved);
visible double colorpurple(treenode involved);
visible double colorrandom(treenode involved);
visible double colorred(treenode involved);
visible double colorsilver(treenode involved);
visible double colorteal(treenode involved);
visible double colorwhite(treenode involved);
visible double coloryellow(treenode involved);
visible treenode combocurrentnode(treenode thecombo);
visible int comborefresh(treenode thecombo);
visible const char* commandlineparam(const char* param);
engine_export int comparetext(char* str1, char* str2, int ignorecase);
visible int comparetrees(treenode a, treenode b);
visible double consoleexecutefs(Window in, Window out);
visible int content(TreeNode*);
visible double contentobj(treenode container);
visible double controlpressed();
visible TreeNode* copyattributes(TreeNode* dest, TreeNode* src, unsigned int mask);
visible int cpcpno(TreeNode*, int);
visible TreeNode* createcopy(TreeNode* classobject, TreeNode* instancecontainer, int samename, int inobject = 0, int cached = 0, int replace = 0);
visible treenode createcoupling(treenode container1, treenode container2);
visible EventDataStruct* createeds(int code, char* string, void* data);
visible double createevent(treenode client, double time, unsigned int code, void* data = 0, treenode involved = 0);
visible double createeventex(treenode client, double time, unsigned int code, void* data, treenode involved, int datasize);
visible TreeNode* createinstance(TreeNode* CLASSNODE, TreeNode* CONTAINERNODE, int nocreatemessage = 0);
visible int createpopup(char* path, char* ofocus, char* vfocus, treenode relativeto, int x, int y, int sx, int sy);
visible int createundorecord(TreeNode* view, TreeNode* object, int undocode, double p1 = 0, double p2 = 0, double p3 = 0);
visible double createview(const char* a, const char* b = "", const char* c = "");
visible const char* currentfile_cstr();
visible double cursorinfo(treenode, double, double, double);
visible double daemonstate(int);
visible int dataplot(treenode datanode, int type, int action, double x, double y, double z);
visible double days(double val);
visible int dbchangetable(char* dbname);
visible int dbclose();
visible double dbexportnode(treenode table, int startrow, int startcol, int numrows, int numcols);
visible double dbexporttable(char* tablename, int startrow, int startcol, int numrows, int numcols);
visible char* dbgetfieldname(int col);
visible int dbgetmetrics();
visible int dbgetmode();
visible int dbnextrow();
visible int dbgetnumcols();
visible int dbgetnumrows();
visible char* dbgettablecell(int row, int col);
visible double dbgettablenum(int row, int col);
visible char* dbgettablestr(double row, double col);
visible double dbimportnode(treenode table, int startrow, int startcol, int numrows, int numcols);
visible double dbimporttable(char* tablename, int startrow, int startcol, int numrows, int numcols);
visible int dbopen(char* dbname, char* command, int tablemode, int loginprompt);
visible int dbsettablecell(int row, int col, char* sval);
visible double dbsettablenum(int row, int col, double val);
visible double dbsettablestr(double row, double col, char* val);
engine_export int dbsqlquery(char* query, int flags);
visible int dbusername(char* username, char* password);
visible double dbviewtable();
visible void deactivatekinematics(treenode infonode);
visible double degreestoradians(double n);
visible double delayevents(double dt);
visible double delayeventsofobject(treenode object, double dt);
visible void deleteeds(EventDataStruct* eds);
visible int deleteFile(const char* filename, bool recursive = false);
visible int deletetablecol(treenode table, int column = 0);
visible int deletetablerow(treenode table, int row = 0);
visible double dellabel(treenode object, char* labelname);
visible double dempirical(char* tablename, int stream = 0);
visible double deselectall();
visible double destroyevent(treenode thenode);
engine_export double destroyeventsofobject(treenode object);
visible double destroyeventsofobject(treenode object, double simtime, int code = 0, char* data = NULL, treenode involvedobject = NULL);
typedef int (*customeventfilter)(treenode object, double simtime, int code, void* data, treenode involved);
engine_export double destroyeventsofobject(treenode object, double simtime, int code, char* data, treenode involvedobject, customeventfilter filter);
visible int destroynode(TreeNode* object);
visible int destroyobject(TreeNode* object);
visible double diffsign(double n1, double n2);
visible double distfromviewpoint(treenode theobject, treenode theview);
visible const char* documentsdir_cstr();
visible void documentusercommands();
visible double draginfo(int op, double val = 0);
visible double draw2dcurve(treenode view, double matrix[4][4], double xcenter, double ycenter, double radius, double startangle, double sweepangle, float red, float green, float blue);
visible double draw3dtext(char* text);
visible double drawbox(double xloc, double yloc, double zloc, double xsize, double ysize, double zsize, int glbeginend = 1);
visible double drawcolumn(double LocX, double LocY, double LocZ, double Sides, double BaseRadius, double TopRadius, double Height, double RotX, double RotY, double RotZ, double Red, double Green, double Blue, double Opacity, double ImageIndexObjectNum, double RepX, double RepY);
visible double drawcube(double LocX, double LocY, double LocZ, double SizeX, double SizeY, double SizeZ, double RotX, double RotY, double RotZ, double Red, double Green, double Blue, double Opacity, double ImageIndexObjectNum, double RepX, double RepY);
engine_export double drawcube(double LocX, double LocY, double LocZ, double SizeX, double SizeY, double SizeZ, double RotX, double RotY, double RotZ, double Red, double Green, double Blue);
visible double drawcylinder(double LocX, double LocY, double LocZ, double BaseRadius, double TopRadius, double Height, double RotX, double RotY, double RotZ, double Red, double Green, double Blue, double Opacity, double ImageIndexObjectNum);
engine_export double drawcylinder(double LocX, double LocY, double LocZ, double BaseRadius, double TopRadius, double Height, double RotX, double RotY, double RotZ, double Red, double Green, double Blue);
visible double drawdisk(double LocX, double LocY, double LocZ, double InnerRadius, double OuterRadius, double StartAngle, double SweepAngle, double RotX, double RotY, double RotZ, double Red, double Green, double Blue, double Opacity, double ImageIndexObjectNum);
visible double drawflattext(char* text);
visible double drawfont(double f);
visible double drawline(treenode viewnode, double x, double y, double z, double x2, double y2, double z2, double red = 0, double green = 0, double blue = 0);
visible void drawobjectpart(TreeNode* viewobj, TreeNode* object, int part);
visible double drawpie(treenode viewnode, double x, double y, double z, double x2, double y2, double z2, double startangle, double endangle, double red, double green, double blue);
visible double drawquad(treenode windownode, double x1, double y1, double z1, double x2, double y2, double z2, double x3, double y3, double z3, double x4, double y4, double z4, double red, double green, double blue);
visible double drawrectangle(double LocX, double LocY, double LocZ, double SizeX, double SizeY, double RotX, double RotY, double RotZ, double Red, double Green, double Blue, double Opacity, double ImageIndexObjectNum, double RepX, double RepY);
engine_export double drawrectangle(double LocX, double LocY, double LocZ, double SizeX, double SizeY, double RotX, double RotY, double RotZ, double Red, double Green, double Blue);
visible double drawshadow(int phase);
visible double drawsphere(double x, double y, double z, double radius, double red, double green, double blue, double opacity = 1, int textureindex = 1);
visible double drawtext(treenode windownode, char* text,
	double x, double y, double z,
	double sx = 1, double sy = 1, double sz = 1,
	double rx = 0, double ry = 0, double rz = 0,
	double red = 0, double green = 0, double blue = 0, double alpha = 1);
visible double drawtomodelscale(treenode object);
visible double drawtoobjectscale(treenode object);
visible double drawtriangle(treenode windownode, double x1, double y1, double z1, double x2, double y2, double z2, double x3, double y3, double z3,
	double red, double green, double blue);
visible treenode dropnodefrom();
visible treenode dropnodeto();
visible double dropx();
visible double dropy();
visible double dropz();
visible void dumpquery(TreeNode* dumpNode, int dumpType);
visible double duniform(int i, int j, int stream = 0);
visible double dynamicsplineall(treenode start);
visible int edscode(EventDataStruct* eds);
visible void* edsdata(EventDataStruct* eds);
visible char* edsstring(EventDataStruct* eds);
visible double empirical(char* tablename, int stream = 0);
visible void endaggregatedundo(TreeNode* view, int id);
visible void endignoreundo();
visible int endoffile();
visible double endreplication(int onlyifexperimenting);
visible double erlang(double locate, double scale, double shape, int stream = 0); // same as gamma
visible double eventget(int index, int thing);
visible double eventmovedown(int index);
visible double eventmoveup(int index);
visible double eventqty();
visible double eventtype(int on);
engine_export TreeNode* eventlisten(treenode object, const char* eventTitle, treenode relayNode, int flags, n10varsdefaultinterface);
visible int EX(const char* T, const char* M, int showsystemconsole = 0);
visible double excelclose(int save);
visible double excelcreatesheet(char* name);
visible double excelcreateworkbook();
visible int exceldeleterange(char* name);
visible double exceldeletesheet(char* name, int allowwarning = 0);
visible double excelexporttable(const char* tablename, int startrow, int startcol, int numrows, int numcols, char rowchar, char colchar);
visible int excelgetrangeparam(char* name, int param);
visible char* excelgetrangesheet(char* name);
visible double excelimporttable(const char* globaltablename, int startrow, int startcol, int numrows, int numcols, char rowchar, char colchar);
visible int excellaunch(char*);
engine_export double excellaunch();
visible double excelmacro(char* m);
visible double excelopen(char* a);
visible int excelquit();
visible double excelrangereadnum(char* name, int row, int col);
visible char* excelrangereadstr(char* name, int row, int col);
visible double excelrangewritenum(char* name, int row, int col, double val);
visible double excelrangewritestr(char* name, int row, int col, char* val);
visible double excelrangesetnumberformat(const char* format, int startRow, int startCol, int rowCount = 0, int colCount = 0);
visible double excelreadnum(int row, int col);
visible const char* excelreadstr(int row, int col);
visible int excelsave(char* filename);
visible int excelsetrange(char* name, int startrow, int startcol, int endrow, int endcol);
visible double excelsetsheet(char* sh);
visible double excelupdatepreferences();
visible char* excelversion();
visible double excelwritenum(int row, int col, double data);
visible double excelwritestr(int row, int col, char* data);
visible double exponential(double locate, double scale, int stream = 0);
visible int exportfullhistory(char* dbname);
visible double extremevalue1a(double locate, double scale, int stream = 0);
visible double extremevalue1b(double locate, double scale, int stream = 0);
visible double factorial(double n1);
visible int familycreate(treenode familycontainer, char* name);
visible int familydelete(treenode familycontainer, char* name);
visible treenode familymember(treenode familycontainer, char* name, int index);
visible int familymemberadd(treenode familycontainer, char* name, treenode node);
visible int familymemberdel(treenode familycontainer, char* name, treenode node);
visible int familymemberqty(treenode familycontainer, char* name);
visible double fastspline(treenode spline, double p);
visible double fastsplineall(treenode start, double res);
visible double fastsplineupdate(treenode spline, double res);
visible void fglColor(float r, float g, float b, float a = 1.0f);
visible int fgldebuglevel(int level);
visible void fglDisable(GLenum x);
visible void fglEnable(GLenum x);
visible void fglLoadIdentity();
visible void fglMatrixMode(GLenum mode);
visible void fglNormal(float x, float y, float z);
visible void fglPopMatrix();
visible void fglPushMatrix();
visible void fglRotate(float angle, float x, float y, float z);
visible void fglScale(float x, float y, float z);
visible void fglTranslate(float x, float y, float z);
visible char* filebrowse(char* ext, char* desc, char* path);
visible double fileclose();
visible int fileexists(const char* filename);
visible char* filereadline_cstr();
visible double fillwithatts(treenode object, int attgroup);
visible treenode findnode(treenode head, char* nodename);
visible treenode findownerobject(treenode);
visible TreeNode* findundorecordbyid(TreeNode* undolist, int uniqueid);
visible void finishundorecord(TreeNode* view, int uniqueid);
visible TreeNode* first(TreeNode*);
visible treenode flowitembin();
visible int flyactive();
visible int flybysimclock();
visible treenode flyendnode(treenode thenode);
visible int flypath(treenode thenode, int, int singlerun);
visible int flypathadd(treenode thenode, int pathno);
visible int flypathreset(treenode thenode, int pathno);
visible double flystart(treenode view);
visible double flystop();
visible double flyto(treenode view, double endtime, double x, double y, double z, double rx, double ry, double rz);
visible int flyupdate();
visible int fpc(char m);
visible int fpd(int m);
visible int fpf(double m);
visible double fpm(double val);
visible int fpr();
visible double fps(double val);
visible int fpt(const char* m);
visible double frac(double n1);
visible int fscheckall(treenode s);
visible double ft(double val);
#ifdef _WINDOWS
visible double gamma(double locate, double scale, double shape, int stream = 0);
#else
#warning "visible double gamma( double locate, double scale, double shape, int stream=0) not implemented on this platform"
#endif
visible unsigned int generateuniqueid();
visible double geometric(double p, int stream = 0);
visible double get(treenode attnode);
visible char* getapplicationtitle();
visible const char* getbundlefieldname(treenode x, int fieldnr);
visible int getbundlefieldnr(treenode x, char* fieldname);
visible int getbundlefieldtype(treenode x, int fieldnr);
engine_export Variant getbundleindexentries(treenode x, int fieldNr, double value);
engine_export Variant getbundleindexentries(treenode x, int fieldNr, const char* value);
engine_export Variant getbundleindexentries(treenode x, const char* fieldName, double value);
engine_export Variant getbundleindexentries(treenode x, const char* fieldName, const char* value);
visible int getbundlenrentries(treenode x);
visible int getbundlenrfields(treenode x);
visible double getchecked(treenode view);
visible double getcolorcomponent(treenode object, double index);
visible TreeNode* getcorefailsafelink();
visible double getcreationtime(treenode object);
visible DeviceContext getcurrentscenedc();
visible TreeNode* getcurrentundorecord(TreeNode* view);
visible double getdatastat(int stat, TreeNode* dataset1, TreeNode* dataset2 = 0, double p1 = 0, double p2 = 0, double p3 = 0);
engine_export double getdatastat(int stat, int nrSamples, double* buffer, double p1, double p2, double p3);
visible int getdatatype(treenode thenode);
visible double getdrawtextmetric(char* text, int fontsize, int metric, int a);
visible double getentrytime(treenode object);
visible double getfilebrowse(char* extension, char* extensiondesc, char* buffer);
visible double getframe(treenode obj);
visible double& getglobalvariableasdouble(int index);
visible int& getglobalvariableasint(int index);
visible std::string& getglobalvariableasstring(int index);
visible treenode& getglobalvariableastreenode(int index);
visible int getglobalvariableindex(char* globalvariablename);
visible double getinput(treenode involved);
visible double getitemtype(treenode object);
visible double getkinematics(treenode infonode, unsigned short type, int index = -1, double updatetime = -1.0);
visible double getlabelnum(treenode object, const char* labelname);
visible double getlastfiletype();
visible double getmodelunitnum(int querytype);
visible char* getmodelunitstr_cstr(int querytype);
visible double getnodenum(treenode attnode);
visible double getobjectimageindex(treenode object);
visible double getobjectshapeindex(treenode object);
visible double getobjecttextureindex(treenode object);
visible double getoutput(treenode involved);
visible Window getparentwindow(Window hWnd);
visible double getpickingdrawfocus(treenode theview, int whattoget, int vftid);
visible int getpickingmode(treenode theview);
visible char* getproperty(char* filename, int property);
visible int getquerycolcount();
visible int getquerymatchcount();
visible int getquerymatchtablerow(char* tableName, int matchNum);
engine_export Variant getqueryvalue(int row, int col);
engine_export Variant getqueryvalue(int row, char* colName);
visible double getrank(TreeNode*);
visible Variant getsdtvalue(TreeNode* sdtNode, const char* valName);
visible double getshapeindex(const char* thename);
visible int getshapenrframes(int shapeindex);
visible double getsoundindex(const char* thename);
visible double getstatenum(treenode object);
engine_export double getstatenum(treenode object, int profilenr);
visible treenode gettablecell(const char* globaltablename, int row, int column);
visible double gettablenum(const char* table, int row, int col);
engine_export double gettablenum(treenode thetable, int row, int col);
visible double gettextureindex(const char* thename);
visible int getundorecordid(TreeNode* undorecord);
visible treenode getvarnode(treenode object, const char* varname);
visible double getvarnum(treenode object, const char* varname);
visible Window getviewhwnd(treenode view, int wndtype);
visible Menu getviewmenu(treenode view, int menutype);
visible double getviewscale(treenode theview);
visible char* getviewtext_cstr(treenode target);
visible int globalcommand_savebyname(TreeNode* xx, char* name, int direct = 0);
visible double go(int fast = 0);
visible double graphtohistogram(treenode graph, treenode hist, double start, double end, double resolution, int xyformat);
visible double help(int mode, char* s1, char* s2);
visible double hideprogressbar();
visible int highestconnection();
visible char* highlightviewtext(treenode target, int pos, int span, int mode);
visible double hours(double val);
visible double howmanyattributes();
visible double howmanycommands();
visible double hypergeometric(int sample, int m, int n, int stream = 0);
visible double in(double val);
visible double inc(treenode attnode, double value);
visible double initialisehistogram(treenode hist, double resolution);
visible void initkinematics(treenode infonode, double x = 0.0, double y = 0.0, double z = 0.0,
	double rx = 0.0, double ry = 0.0, double rz = 0.0, int _flags = 0, int _relativelocs = 0);
engine_export void initkinematics(treenode infonode, treenode object, int _flags = 0, int _relativelocs = 0);
visible TreeNode* inobject(TreeNode*, int);
visible double inputopen(treenode obj);
visible treenode insertcopy(treenode original, treenode container);
visible double inversegaussian(double locate, double scale, double shape, int stream = 0);
visible double inverseweibull(double locate, double scale, double shape, int stream = 0);
visible double invertedweibull(double locate, double scale, double shape, int stream = 0);
visible int ipopen(TreeNode* object, int index);
visible int ipopno(TreeNode*, int);
visible int ipready(TreeNode* object, int index);
visible int isclasstype(treenode obj, int classtype);
engine_export int isclasstype(treenode obj, const char* classtype);
visible int iskeydown(int key = 0);
visible double johnsonbounded(double a, double b, double shape1, double shape2, int stream = 0);
visible double johnsonunbounded(double locate, double scale, double shape1, double shape2, int stream = 0);
visible Window keyboardfocus(Window x);
visible double laplace(double locate, double scale, int stream = 0);
visible TreeNode* last(TreeNode*);
visible treenode lastclickednode();
visible double lastkey();
visible double lastkeydown();
visible double lastkeyup();
visible treenode library();
visible int license();
visible double listboxrefresh(treenode thecombo);
visible double listinlist(n30argsdefaultinterface);
visible double listmax(n30argsdefaultinterface);
visible double listmaximum(n30argsdefaultinterface);
visible double listmean(n30argsdefaultinterface);
visible double listmin(n30argsdefaultinterface);
visible double listminimum(n30argsdefaultinterface);
visible double listmul(n30argsdefaultinterface);
visible double listsub(n30argsdefaultinterface);
visible double listsum(n30argsdefaultinterface);
visible int lladd(TreeNodeListHead* x, TreeNode* toadd);
visible void lladddata(TreeNode* owner, int datatype);
visible TreeNode* llbranch(TreeNode* node);
visible void lldelete(TreeNode* x);
visible TreeNode* llfind(TreeNode* x, char* name);
visible int llgetallocsize();
visible void* llgetdata(TreeNode* node);
visible TreeNode* llinsert(TreeNodeListHead* node, TreeNode* container, TreeNode* newTreeNode);
visible int llinsertbranch(TreeNode* x);
visible TreeNode* llinsertinto(TreeNode* node, TreeNode* container, TreeNode* newTreeNode);
visible TreeNode* lllastitem(TreeNode* x);
visible TreeNode* llnew();
visible size_t llposition(TreeNode* x);
visible double llreceivemessage(TreeNode* node, int code, EventDataStruct* data, char* name, int group, CallPoint* callpoint, TreeNode* associated);
visible void llremove(TreeNodeListHead* owner, TreeNode* x);
visible double* llsdf(TreeNode* node);
visible int llsize(TreeNode* node);
visible TreeNode* llstep(TreeNode* node, int size);
visible double loadimage(char* thefile, char* thename);
visible double unloadimage(int textureid);
visible double loadthreedobject(char* thefile, char* thename);
visible double* loc_clock();
visible TreeNode* loc_medialist();
visible TreeNode* loc_medialist_images();
visible TreeNode* loc_medialist_objects();
visible TreeNode* loc_medialist_sounds();
visible TreeNode* loc_tools();
visible TreeNode* loc_undolist();
visible double logarithmic(double theta, int stream = 0);
visible void logevent(int eventCode, treenode object = NULL, treenode involved = NULL, double p1 = 0, double p2 = 0, double p3 = 0, double p4 = 0);
engine_export void logevent(char* name, treenode object = NULL, treenode involved = NULL, double p1 = 0, double p2 = 0, double p3 = 0, double p4 = 0);
visible double logistic(double locate, double scale, int stream = 0);
visible double loglaplace(double locate, double scale, double shape, int stream = 0);
visible double loglogistic(double locate, double scale, double shape, int stream = 0);
visible double lognormal(double locate, double scale, double shape, int stream = 0);
visible double lognormal2(double locate, double scale, double shape, int stream = 0);
visible size_t maintenance(int command, double state, char* info = (char*)"");
visible TreeNodeListHead* maintree();
visible double makeactive(treenode obj);
visible double makehisto(treenode data, treenode dest, int nrofbuckets, double minval, double maxval);
visible double maxof(double a, double b);
visible double mediareset();
visible Menu menubelow(Menu m, double x);
visible double menucheck(Menu m, double x, double y);
visible double menugray(Menu m, double x, double y);
visible Menu menumain();
visible void mesh(treenode meshnode, unsigned int perVertexAttribs, unsigned int flags);
visible int  meshaddvertex(treenode meshnode);
visible void meshaddcustomvertexattrib(treenode meshnode, const char* name, int componentsPerVertex, GLenum type, bool isNormalized);
visible void meshsetvertexattrib(treenode meshnode, unsigned int vertIndex, unsigned int attribId, float p1, float p2 = 0, float p3 = 0, float p4 = 0);
visible void meshdraw(treenode meshnode, int drawMode, int offset, int count, int stride = 0);
visible int meshaddindex(treenode meshnode, unsigned int index);
visible double meshinfo(treenode meshnode, unsigned int type, unsigned int index = 0, unsigned int param = 0);
visible double minof(double a, double b);
visible double minutes(double val);
visible treenode model();
visible const char* modeldir_cstr();
visible int moveobject(TreeNode* client, TreeNode* destination, int port = 0);
engine_export int moveobject(TreeNode* client, TreeNode* destination, int port, int receivingport);
visible int moveobjectstatsupdate_content(TreeNode* container, unsigned int);
visible int moveobjectstatsupdate_staytime(TreeNode* container, double* client);
visible int movetablecol(treenode table, int column, int newcolumn);
visible int movetablerow(treenode table, int row, int newrow);
visible double mph(double val);
visible double msg(char* a, char* b, int mode = 0);
visible char* namebbgetbuffer(TreeNode* node);
visible int namebbgetsize(TreeNode* node);
visible int namebbsetsize(TreeNode* node, int size);
visible double nametomodelpath(treenode toname, treenode thenode);
visible double negbinomial(int s, double p, int stream = 0);
visible treenode next(treenode node);
visible void nextforobjectselectionset(treenode* curnode, treenode topnode);
engine_export treenode nextforobjecttreeunder(treenode curnode, treenode topnode);
visible treenode nodeadddata(treenode target, int type);
visible treenode node(char* path, treenode from = 0);
visible int nodealloc(treenode curnode, unsigned int size);
visible double nodebreak(treenode attnode);
visible treenode nodedeldata(treenode target);
engine_export treenode nodefromwindow(Window x);
visible treenode nodeinsertafter(treenode target);
visible treenode nodeinsertinto(treenode target);
visible double nodejoin(treenode attnode, treenode attnode2);
visible treenode nodepoint(treenode attnode, treenode attnode2);
visible char* nodetomodelpath_cstr(treenode from, int byname);
visible int nodetotextpath(TreeNode* node, char* buffer);
visible int nodetotextpath_indexed(TreeNode* node, char* buffer);
visible double normal(double mean, double stddev, int stream = 0);
visible double nrcp(TreeNode* node);
visible double nrip(TreeNode* node);
visible double nrop(TreeNode* node);
visible double numconnections();
visible double objectexists(TreeNode*);
visible int objectsoundcode(TreeNode* object, int defaultsound);
visible int odtgetallocsize();
visible int openallip(TreeNode*);
visible int openallop(TreeNode*);
visible int openflexsimchart(char* file1, char* file2);
visible double openglcolor(double red, double green, double blue, double alpha);
visible double opengllighting(double onoff);
visible double openinput(TreeNode* object);
visible double openip(TreeNode* node, int index);
visible double openop(TreeNode* node, int index);
visible double openoutput(TreeNode* object);
visible int opipno(TreeNode*, int);
visible int opopen(TreeNode* object, int index);
visible int opready(TreeNode* object, int index);
visible TreeNode* outobject(TreeNode*, int);
visible double outputopen(treenode obj);
visible double outputtreecontent(treenode target, char* filename);
visible treenode ownerobject(treenode);
visible treenode ownerview(treenode);
visible double pareto(double min, double scale, int stream = 0);
visible const char* parg_cstr();
visible double parqty(CallPoint* callpoint);
visible int particlecreate(TreeNode* c);
visible int particlemove(TreeNode* client, TreeNode* destination);
visible int pc(char m);
visible int pd(int m);
visible const char* pdir_cstr();
visible double pearsont5(double locate, double scale, double shape, int stream = 0);
visible double pearsont6(double locate, double scale, double shape1, double shape2, int stream = 0);
visible int pf(double m);
visible const char* pfile_cstr();
visible double pi();
visible double pickcolor(double red, double green, double blue);
visible double pickcolornode(treenode cnode);
visible double pickedcolorblue();
visible double pickedcolorgreen();
visible double pickedcolorred();
visible double pickfile(char* extension, char* extensiondesc, char* defaultreturn = (char*)"");
visible int picklistapply(treenode thecombo);
visible double poisson(double mean, int stream = 0);
visible Menu popupmenu(treenode thenode);
visible double postclosewindowmessage(treenode viewnode);
visible double postmovewindowupdate(treenode thenode);
visible int pr();
visible treenode prev(treenode node);
visible void profilekinematics(treenode infonode, short index = -1);
visible int pt(const char* m);
visible double qstudentt(double quant, int df);
visible double radianstodegrees(double n);
visible double randantithetic(int on);
visible double randinit(double stream, double value = 0);
visible double randnext(double stream);
visible double randomwalk(double locate, double scale, double shape, int stream = 0);
visible long randstate(int stream);
visible TreeNode* rank(TreeNode*, int);
visible treenode rankobj(treenode container, int therank);
visible size_t realtime(int thing);
visible int rebindobjectattributes(treenode object);
visible void recover(int phase);
visible double redirectconsole(int console, treenode newwindow);
visible int refreshcommand(treenode commandnode, int structure = 0);
visible int refreshcommandlist();
visible double refreshglobalvariables();
visible int refreshview(treenode xx);
visible treenode reftable(const char* globaltablename);
visible int registereventtype(const char* name);
visible int removeallcouplingreferences(treenode xx);
visible int removebundleentry(treenode x, int entrynum);
visible int removeeventsofobject(treenode object, double simtime = -1, int code = 0, char* data = NULL, treenode involvedobject = NULL);
visible int removefirstbundleentry(treenode x);
visible int removelastbundleentry(treenode x);
visible double repaintall();
visible double repaintallactive();
visible int repaintview(treenode xx);
visible double replacedata_n(treenode start, double value, double replace);
visible double replacedata_s(treenode start, char* pattern, char* replace, int replication);
visible double replacename(treenode start, char* pattern, char* replace, int replaceyesno);
visible double report(treenode node, char*, int);
visible double reportmode(int mode);
visible void reportobjectfunctionexception(char* objectfunctionname, treenode instance, treenode involved, treenode theclass);
visible double repositionhighlightededits(treenode treeviewnode);
visible double resetexperiment();
visible double resetlayer(treenode curlayer);
visible double resetstats();
visible unsigned int resetuniqueid(treenode theitem);
visible int restoreeventsofobject(treenode object, double delaytime, double simtime = -1, int code = 0, char* data = NULL, treenode involvedobject = NULL);
visible void resumeanimation(treenode theobject, int animnr, int resumeAtType = 0, double resumeAtVal = 0);
engine_export void resumeanimation(treenode theobject, char* animname, int resumeAtType = 0, double resumeAtVal = 0);
visible double resumeinput(treenode object);
visible double resumeoutput(treenode object);
#if defined _MSC_VER && _MSC_VER < 1800
visible double round(double n1);
#else
using std::round;
#endif
engine_export double round(double n1, int precision);
visible double rundocument(const char* cmd, const char* file);
visible double runexpertfit();
visible double runfunction(int noreset = 0);
visible double runprogram(const char* s);
visible double runspeed(double n1, double n2 = -1);
visible double savetree(treenode tree, char* extension, char* extensiondesc, char* path);
visible int scaleeventsofobject(treenode object, double scalefactor, double eventtime, int code);
visible double scalekinematicstotime(treenode kinematics, int kinematicnr, double totime);
visible double searchdata_n(treenode start, double value);
visible double searchdata_s(treenode start, char* pattern, int replication);
visible treenode searchfornode(char* searchstr, treenode rootnode, int nth = 1, int searchobjects = 0);
visible double searchname(treenode start, char* pattern);
visible double selectedx(treenode target);
visible double selectedy(treenode target);
visible double selectedz(treenode target);
visible int sendwindowmessage(treenode view, int command, WindowParam1 wParam, WindowParam2 lParam);
visible double serveraccept(int sock);
visible double servercloseconnection(int sock);
visible double serverclosemain();
visible double servercreatemain(int sock);
visible double serverreceive(int skt, char* Buf, int BufSize, int NoBlock);
visible double serversend(int skt, char* Msg, int len);
visible treenode set(treenode attnode, double val);
visible int setapplicationtitle(char* title);
visible double setcameradirection(treenode view,
	double x, double y, double z,
	double rx, double ry, double rz);
visible double setcameravolume(treenode view,
	double w, double h, double nearc, double farc,
	double mag, double fov,
	double orthopers, double firstperson);
visible double setchecked(treenode view, int checked);
visible double setcolor(treenode involved, double red, double green, double blue);
visible int setcustomdisplayfunction(treenode xx, CustomDisplayFunction thefunc);
visible double setdrawnamefunction(int boxwidth, int boxheight, treenode x, double p1, double p2, double p3);
visible double setdropcoords(treenode theview);
visible void setdropcoordsmanual(double x, double y, double z);
visible double setframe(treenode obj, int inframe);
visible double setitemtype(treenode object, double value);
visible void setkinematicsrotoffset(treenode infonode, double _rx, double _ry, double _rz);
visible double setlabelnum(treenode object, const char* labelname, double value);
visible double setmessageloopsleep(double a, double b);
visible treenode setname(treenode attnode, const char* s);
visible treenode setnodenum(treenode attnode, double value);
visible double setobjectbillboard(treenode thenode, int mode);
visible double setobjectimageindex(treenode object, double index);
visible double setobjectshapeindex(treenode object, double index);
visible double setobjecttextureindex(treenode object, double index);
visible int setpickingdrawfocus(treenode theview, treenode focus, int selectiontype, treenode secondaryfocus = NULL, int flags = 0);
visible double setprogressbar(double val);
visible int setproperty(char* filename, int property, char* newvalue);
visible void setquerynode(TreeNode* queryNode);
visible TreeNode* setrank(TreeNode*, int);
visible double setrot(treenode involved, double rx, double ry, double rz);
visible TreeNode* setsdtvalue(TreeNode* sdtNode, const char* valName, Variant toVal);
visible double setselectedobject(treenode target, treenode newselected);
visible double setsize(treenode involved, double sx, double sy, double sz);
visible int setstate_s(TreeNode* object, char* name);
visible double settablenum(const char* table, int row, int col, double value);
engine_export double settablenum(treenode thetable, int row, int col, double val);
visible double settablesize(char* globaltablename, int nrows, int ncols, int type = 0, int overwrite = 0);
engine_export double settablesize(treenode table, int nrows, int ncols, int type = 0, int overwrite = 0);
visible double setvarnum(treenode object, char* varname, double val);
visible double setvarstr(treenode object, char* varname, char* val);
visible void setviewtext(treenode target, const char*);
visible double shiftpressed();
visible double showcompilerconsole();
visible int showhtmlhelp(char* path);
visible double showprogressbar(char* text);
visible double sign(double n1);
visible treenode so();
visible double socketend();
visible double socketinit();
visible double sorttable(char* table, int col);
engine_export double sorttable(treenode table, int col);
engine_export double sorttable(int table, int col);
visible double soundchange(treenode soundnode, double sound, double vol, double pit, double rep, double bal);
visible double soundload(char*);
visible double soundplay(treenode soundnode, double sound, double vol, double pit, double rep, double bal);
visible double soundplayfile(treenode soundnode, char* soundfilename, double vol, double pit, double rep, double bal);
visible double soundstop(treenode soundnode, double sound);
visible double spacebase(int n);
visible double spacerotate(double x, double y, double z);
visible double spacescale(double x, double y, double z);
visible double spacetranslate(double x, double y, double z);
visible double spline(treenode spline, double p);
visible double splinedraw(treenode spline);
visible double splinedrawextrusion(treenode thespline, double step, double wide, double high, int textop, int texside);
visible double splinelength();
visible double splineposobject(treenode object, treenode relative);
visible double splinerx();
visible double splinery();
visible double splinerz();
visible double splinex();
visible double spliney();
visible double splinez();
visible void startanimation(treenode theobject, int animnr, int durationtype = 0, double duration = 0, int repeattype = 0, double repeatvalue = 0);
engine_export void startanimation(treenode theobject, char* animname, int durationtype = 0, double duration = 0, int repeattype = 0, double repeatvalue = 0);
visible double startlisten(treenode listener);
visible double statisticaltime();
visible double statsenablemask(double x = -1);
visible double step();
visible double stop(int fast = 0);
visible void stopanimation(treenode theobject, int animnr);
engine_export void stopanimation(treenode theobject, char* animname);
visible double stopinput(treenode object);
visible double stoplisten(treenode listener);
visible double stopoutput(treenode object);
visible double stoptime(double stopTime, double stopNum = 1);
#pragma push_macro("stringreturn")
#undef stringreturn
visible void stringreturn(char* instr, CallPoint* cp);
#pragma pop_macro("stringreturn")
visible int stringsearch(char* str1, char* substr, int startpos);
engine_export int stringsearch(char* str1, char* substr, int startpos, int flags);
visible int stringsequal(const char* s1, const char* s2);
visible char* stringtoken(char* token, char* delimit);
visible double stringtonum(const char* str1);
visible double suspenddraw(double x = -1);
visible treenode sv();
//visible int swapnoderanks(TreeNode*, int, int); // Defined in FlexsimDefs.h
visible int swaptablecols(treenode table, int column, int column2);
visible int swaptablerows(treenode table, int row, int row2);
visible double switch_activelisteners(treenode node, int on = -1);
visible double switch_cppfunc(treenode node, int on = -1);
visible double switch_destroyonreset(treenode node, int on = -1);
visible double switch_dllfunc(treenode node, int on = -1);
visible double switch_enablestats(treenode node, int on = -1);
visible double switch_expanded(treenode node, int on = -1);
visible int switch_flexscript(treenode thenode, int toggle = -1);
visible double switch_hidden(treenode node, int on = -1);
visible double switch_hidebase(treenode node, int on = -1);
visible double switch_hideconnectors(treenode node, int on = -1);
visible double switch_hidecontents(treenode node, int on = -1);
visible double switch_hidelabel(treenode node, int on = -1);
visible double switch_hideshape(treenode node, int on = -1);
visible double switch_noselect(treenode node, int on = -1);
visible double switch_preservecoupling(treenode node, int on = -1);
visible double switch_orphancoupling(treenode node, int on = -1);
visible double switch_protected(treenode node, int on = -1);
visible double switch_selected(treenode node, int on = -1);
visible double switch_showobject(treenode node, int on = -1);
visible double switch_statelocked(treenode node, int on = -1);
visible double switch_stateused(treenode node, int on = -1);
visible double switch_variable(treenode object, char* variable, int on = -1);
visible Window systemwindow(int window);
visible int templatetocode(treenode thecode, treenode theedit);
visible int toggleallcodestates(treenode x, int ascpp);
visible treenode tonode(size_t x);
engine_export treenode tonode(double x);
engine_export treenode tonode(char* x);
engine_export treenode tonode(void* x);
visible void* toptr(size_t x);
visible double tracemaskevents(double x = -1);
visible double tracemaskobject(treenode x = (treenode)1);
visible double tracemasktime(double x = -1, double y = -1);
visible double trackpopup(treenode x);
visible double transfernode(treenode thenode, treenode newcontainer);
visible double transfernodeobj(treenode thenode, treenode newcontainer);
visible double transformvectorxy(double* vector, double matrix[4][4]);
visible double transitionport();
visible int treewin__loadtree(TreeNode* xx, char* buffera);
visible double triangular(double min, double max, double mode, int stream = 0);
#if _MSC_VER < 1800
visible double trunc(double n1);
#else
using std::trunc;
#endif
visible double uniform(double a, double b, int stream = 0);
visible treenode up(treenode node);
visible void updateanimation(treenode object);
engine_export void updateanimation(treenode theobject, double updatetime, int animationnr = 0);
engine_export void updateanimation(treenode theobject, double updatetime, int animationnr, int force);
visible void updatekinematics(treenode infonode, treenode object, double updatetime = -1.0);
visible double updatestate(treenode obj);
engine_export double updatestate(treenode obj, int profilenr);
visible void updateundorecord(TreeNode* view, int uniqueid, int updatetype = 0, double p1 = 0, double p2 = 0);
visible double uselisteners(double x = -1);
visible Variant userinput(treenode variable, char* prompt, int stop = 0);
visible const char* userdatadir_cstr();
visible const char* programdatadir_cstr();
//visible int validlink(TreeNode*, const char*); // Defined in FlexsimDefs.h
visible double valuetohistogram(double val, treenode hist, double start, double end, double resolution, int xyformat, double* _lo, double* _hi);
visible double* vectorproject(treenode origin, double xposition, double yposition, double zposition, treenode ontoobject, volatile double* tempvector);
visible double vectorprojectx(treenode origin, double xposition, double yposition, double zposition, treenode ontoobject);
visible double vectorprojecty(treenode origin, double xposition, double yposition, double zposition, treenode ontoobject);
visible double vectorprojectz(treenode origin, double xposition, double yposition, double zposition, treenode ontoobject);
visible double viewdist(treenode v, treenode ob);
visible TreeNodeListHead* views();
visible double viewtofile(treenode theview, const char* s);
engine_export double viewtofile(treenode theview, const char* s, int w, int h);
visible double weibull(double locate, double scale, double shape, int stream = 0);
visible Window windowfromnode(treenode x);
visible double windowgray(Window control, int gray);
visible Menu windowmenu(treenode thenode);
visible double windowmove(Window w, double a, double b, double c, double d, double refresh);
visible double windowshow(Window w, double show);
visible int windowstyle(treenode view, int style, int doexstyle = 0);
visible double xcenter(treenode obj);
visible double xloc(treenode obj);
visible double xrot(treenode obj);
visible double xsize(treenode obj);
visible double ycenter(treenode obj);
visible double yloc(treenode obj);
visible double yrot(treenode obj);
visible double ysize(treenode obj);
visible double zcenter(treenode obj);
visible double zloc(treenode obj);
visible double zrot(treenode obj);
visible double zsize(treenode obj);

/*** DEPRECATED FUNCTIONS ***/
visible double add(double n1, double n2);
visible treenode anode(double x);
visible double anum(char* x);
visible void* aptr(double);
visible treenode att(treenode node, int index);
visible treenode att_s(treenode node, const char* name);
visible TreeNode* cell(TreeNode* node, size_t xpos, size_t ypos);
visible TreeNode* cellrowcolumn(TreeNode* node, size_t row, size_t col);
visible double colorrgb(treenode involved, double red, double green, double blue);
visible int cppgetnumtokens(treenode thetext);
visible int cppgetphrasetoken(treenode thetext, int index, ByteBlock* resultblock);
visible int cppgettitletoken(treenode thetext, int index, ByteBlock* resultblock);
visible int cppgettoken(treenode thetext, int index, ByteBlock* resultblock);
visible int cppsettitletoken(treenode thetext, int index, ByteBlock* resultblock, char* newtext);
visible int cppsettoken(treenode thetext, int index, ByteBlock* resultblock, char* newtext);

visible int dbwritechanges();
visible double divide(double n1, double n2);
visible double drawrect(treenode viewnode, double x, double y, double z, double x2, double y2, double z2, double red, double green, double blue);
visible double eq(double n1, double n2);
visible double excelexportnode(treenode table, int startrow, int startcol, int numrows, int numcols, char rowchar, char colchar);
visible double excelimportnode(treenode table, int startrow, int startcol, int numrows, int numcols, char rowchar, char colchar);
engine_export double excelimportnode(treenode table, int startrow, int startcol, int numrows, int numcols);
visible char* excelread(int Row, int Col, char rowchar = 'r', char colchar = 'c');
visible char* excelwrite(char* inStr, int Row, int Col, char RowChar = 'r', char ColChar = 'c');
engine_export Variant executefsnode(TreeNode* fsNode, TreeNode* c, TreeNode* i, const Variant& data = Variant(), int unused = 0);
engine_export Variant executestring(const char* str, treenode c = NULL, treenode i = NULL, const Variant& data = Variant());
visible double ge(double n1, double n2);
visible double gt(double n1, double n2);
visible int installpackage(char* packagefile);
visible double le(double n1, double n2);
visible double loadsound(char*, char*);
visible double lt(double n1, double n2);
visible double modeleditmode(int mode);
visible double module(int cmd, ptrdiff_t ptr, char* par, double n);
visible double mul(double n1, double n2);
visible size_t ncols(TreeNode* node);
visible double ne(double n1, double n2);
visible size_t nrows(TreeNode* node);
visible int objectconnect(TreeNode* a, TreeNode* b);
visible double optquest(int command, int action, double numparam, char* strparam, double p1, double p2, double p3, double p4);
visible double particleset(treenode viewnode, int setno, int cmd, double p1 = 0, double p2 = 0, double p3 = 0, double p4 = 0, double p5 = 0, double p6 = 0);
visible double relloc(treenode primary, treenode start, int xyz);
visible double reset();
visible double resetmodel(int mode = 0);
visible double richeditaddtext(treenode theedit, char* thetext, int protectedflag, int lastone);
visible char* richedittoken(treenode theedit, int index, ByteBlock* resultblock);
visible double settable(TreeNode* node, size_t xsize, size_t ysize, double datatype, double overwrite);
visible int showgraphicinfo(int showhide, char* file = (char*)"");
visible double spaceglobal();
visible double spaceobject();
visible int stick(int stickno, int xyzb, size_t w, unsigned int p);
visible double sub(double n1, double n2);
visible int undos(int state, int set);
visible treenode var(treenode node, int index);
visible treenode var_s(treenode node, const char* name);
visible double webcommand(char* commandname, n10argsinterface);

// The following are special types of definition. Add your own special function definitions
// to the end of this file.
inline TreeNode* sets(treenode attnode, string s){
	bbsetsize(attnode, s.length() + 1);
	char* deststr = bbgetbuffer(attnode);
	strcpy(deststr, s.c_str());
	return attnode;
}
inline string concat(string p1,string p2,string p3="",string p4="",string p5="",string p6="",string p7="",string p8="",string p9="",string p10="",string p11="",string p12="",string p13="",string p14="",string p15="",string p16="",string p17="",string p18="",string p19="",string p20="")
	{string x = "";x.append(p1);x.append(p2);x.append(p3);x.append(p4);x.append(p5);x.append(p6);x.append(p7);x.append(p8);x.append(p9);x.append(p10);x.append(p11);x.append(p12);x.append(p13);x.append(p14);x.append(p15);x.append(p16);x.append(p17);x.append(p18);x.append(p19);x.append(p20);return x;}
inline treenode node(string path, treenode from = NULL){return node((char*)path.c_str(), from);}
inline string gets(treenode thenode){char* x = bbgetbuffer(thenode);if(x) return string(x); else return string("");}
inline string getnodestr(treenode thenode){string x = bbgetbuffer(thenode);return x;}
inline treenode reftable(string globaltablename){return reftable(globaltablename.c_str());}
inline string numtostring(double val, int wid=0, int prec=0)
{
  char buffer[1024];
  sprintf(buffer,"%*.*f",wid,prec,val);
  string x=buffer;
  return x;
}
inline treenode reftable(int globaltablerank){
	string nodestr = concat("/Tools/GlobalTables/",numtostring(globaltablerank,0,0),">variables/data");
	return node(nodestr.c_str(),model());

}

inline treenode label(treenode obj, int labelrank){return rank(labels(obj), labelrank);}
inline treenode addlabel(treenode obj, string labelname, double value = 0){return addlabel(obj, labelname.c_str(), value);}
inline treenode addlabel(treenode obj, string labelname, string value){treenode label = addlabel(obj, labelname.c_str(), 0);nodeadddata(label, DATA_BYTEBLOCK);sets(label, value);return label;}
visible treenode label(treenode object, const char* labelname);
inline treenode label(treenode object, string labelname){return label(object, labelname.c_str());}
inline double getlabelnum(treenode object, int labelrank){return get(rank(labels(object), labelrank));}
inline double getlabelnum(treenode object, string labelname){return getlabelnum(object, labelname.c_str());}
inline string getlabelstr(treenode object, int labelrank){return gets(rank(labels(object), labelrank));}
inline string getlabelstr(treenode object, string labelname){string path = concat("/",labelname); return gets(node((path.c_str()), labels(object)));}
inline double setlabelnum(treenode object, int labelrank, double val){set(rank(labels(object), labelrank), val);return 0;}
inline double setlabelnum(treenode object, string labelname, double val){return setlabelnum(object, labelname.c_str(), val);}
inline double setlabelstr(treenode object, int labelrank, string val){sets(rank(labels(object), labelrank), val);return 0;}
inline double setlabelstr(treenode object, string labelname, string val){sets(label(object, labelname), val);return 0;}
inline double gettablenum(string tablename, int row, int col){return gettablenum(tablename.c_str(), row, col);}
inline treenode gettablecell(treenode thetable, int row, int col){return cellrc(thetable, row, col);}
inline treenode gettablecell(string tablename, int row, int col){return gettablecell(tablename.c_str(), row, col);}
inline treenode gettablecell(int table, int row, int col){return cellrc(reftable(table), row, col);}
engine_export const char* gettablestr_cstr(treenode thetable, int row, int col);
inline string gettablestr(treenode thetable, int row, int col){return gettablestr_cstr(thetable, row, col);}
inline string gettablestr(string tablename, int row, int col){return gettablestr_cstr(reftable(tablename.c_str()), row, col);}
engine_export const char* gettablestr_cstr(int table, int row, int col);
inline string gettablestr(int table, int row, int col){return gettablestr_cstr(table, row, col);}
inline double settablenum(string tablename, int row, int col, double val){settablenum(tablename.c_str(), row, col, val);return 0;}
visible double settablestr(const char * table, int row, int col, const char * value);
engine_export double settablestr(treenode thetable, int row, int col, const char* val);
inline double settablestr(treenode thetable, int row, int col, string val){ return settablestr(thetable, row, col, val.c_str());}
inline double settablestr(string tablename, int row, int col, string val){return settablestr(tablename.c_str(), row, col, val.c_str());}
engine_export double settablestr(int table, int row, int col, const char* val);
inline treenode addtablerow(char* tablename, int row=0, int datatype=0){return addtablerow(reftable(tablename),row,datatype);}
inline treenode addtablerow(int table, int row=0, int datatype=0){return addtablerow(reftable(table),row,datatype);}
inline treenode addtablerow(string tablename, int row=0, int datatype=0){return addtablerow(reftable(tablename),row,datatype);}
inline int deletetablerow(char* tablename, int row=0){return deletetablerow(reftable(tablename),row);}
inline int deletetablerow(int table, int row=0){return deletetablerow(reftable(table),row);}
inline int deletetablerow(string tablename, int row=0){return deletetablerow(reftable(tablename),row);}
inline int movetablerow(char* tablename, int row, int newrow){return movetablerow(reftable(tablename),row,newrow);}
inline int movetablerow(int table, int row, int newrow){return movetablerow(reftable(table),row,newrow);}
inline int movetablerow(string tablename, int row, int newrow){return movetablerow(reftable(tablename),row,newrow);}
inline int swaptablerows(char* tablename, int row, int row2){return swaptablerows(reftable(tablename),row,row2);}
inline int swaptablerows(int table, int row, int row2){return swaptablerows(reftable(table),row,row2);}
inline int swaptablerows(string tablename, int row, int row2){return swaptablerows(reftable(tablename),row,row2);}
inline treenode addtablecol(char* tablename, int col=0, int datatype=0){return addtablecol(reftable(tablename),col,datatype);}
inline treenode addtablecol(int table, int col=0, int datatype=0){return addtablecol(reftable(table),col,datatype);}
inline treenode addtablecol(string tablename, int col=0, int datatype=0){return addtablecol(reftable(tablename),col,datatype);}
inline int deletetablecol(char* tablename, int col=0){return deletetablecol(reftable(tablename),col);}
inline int deletetablecol(int table, int col=0){return deletetablecol(reftable(table),col);}
inline int deletetablecol(string tablename, int col=0){return deletetablecol(reftable(tablename),col);}
inline int movetablecol(char* tablename, int col, int newcol){return movetablecol(reftable(tablename),col,newcol);}
inline int movetablecol(int table, int col, int newcol){return movetablecol(reftable(table),col,newcol);}
inline int movetablecol(string tablename, int col, int newcol){return movetablecol(reftable(tablename),col,newcol);}
inline int swaptablecols(char* tablename, int col, int col2){return swaptablecols(reftable(tablename),col,col2);}
inline int swaptablecols(int table, int col, int col2){return swaptablecols(reftable(table),col,col2);}
inline int swaptablecols(string tablename, int col, int col2){return swaptablecols(reftable(tablename),col,col2);}

inline double time(){return loc_clock()[0];}
inline double msg(string a, string b, int mode = 0){return msg((char*)a.c_str(),(char*)b.c_str(),mode);}
inline double sqr(double n1){return n1*n1;}

inline TreeNode* setnodestr(treenode attnode, string s){
	bbsetsize(attnode, s.length() + 1);
	char* deststr = bbgetbuffer(attnode);
	strcpy(deststr, s.c_str());
	return attnode;
}

inline double dllstop(){return stop(0);}
inline int dllmoveobject(treenode client, treenode destination){return moveobject(client, destination, 0);}

inline TreeNode* setname(treenode obj, string name)
{
	return setname(obj, name.c_str());
}
inline TreeNode* setnodename(treenode obj, string name)
{
	return setname(obj, name.c_str());
}
inline string getname(treenode obj)
{
  string x="NULL";
  if(validlink(obj, (char*)"getname")) x=namebbgetbuffer(obj);
  return x;
}
inline string getnodename(treenode obj)
{
	string s = namebbgetbuffer(obj);
	return s;
}
inline string nodetopath(treenode from, int byname = 0)
{
	string s;
	if(!objectexists(from)) return "";
	char buffer[1024];
	if(byname)
		nodetotextpath(from,buffer);
	else nodetotextpath_indexed(from,buffer);

	s=buffer;
	return s;
}
inline string nodetomodelpath(treenode from, int byname = 0)
{
	string s = nodetomodelpath_cstr(from, byname);
	return s;
}

inline int stringlen(string str)
{
	return str.length();
}
inline double stringtonum(string str)
{
	return stringtonum(str.c_str());
}
inline TreeNode* tonode(TreeNode* x) { return x; }
inline TreeNode* tonode(const Variant& x) { return Variant::interpretLegacyDouble(x.forceLegacyDouble()); }
inline double tonum(double x) {return x;}
inline double tonum(treenode x) {return ptrtodouble((void*)x);}
inline double tonum(char* x) {return ptrtodouble((void*)x);}
inline double tonum(const std::string& x) { return ptrtodouble((void*)x.c_str()); }
inline string stringcopy(string str1, int start, int len)
{
  char *buffer=new char[len+5];
  strncpy(buffer,str1.c_str()+start-1,len);
  buffer[len]=0;
  string x=buffer;
  delete [] buffer;
  return x;
}
inline string stringpart(string str1, int start, int len)
{
  char *buffer=new char[len+5];
  strncpy(buffer,str1.c_str()+start,len);
  buffer[len]=0;
  string x=buffer;
  delete [] buffer;
  return x;
}
inline string tostring(char * c)
{
  string x=c;
  return x;
}
inline int comparetext(string str1, string str2)
{
  return str1==str2;
}
inline int comparetext(string str1, string str2, int ignorecase){return comparetext((char*)str1.c_str(), (char*)str2.c_str(), ignorecase);}
inline int stringcompare(string str1, string str2)
{
  return strcmp(str1.c_str(), str2.c_str());
}
inline char *stringtopchar(string & s){return ((char*)s.c_str());}
inline string getviewtext(treenode target)
{
	string s = getviewtext_cstr(target);
	return s;
}
inline char * apchar(string &s){return ((char*)s.c_str());}
inline char * apchar(void *s){return (char*)s;}
inline string pfile(){return (string)pfile_cstr();}
inline string parg(){return (string)parg_cstr();}
inline string strascii(int c)
{
  char cc[2];
  sprintf(cc,"%c",c);
  string ss=cc;
  return ss;
}
inline string strquote(string s)
{
  string ss="";
  ss = "\""+ s + "\"";
  return s;
}
inline int executefsfile(string s, int direct = 0){return _executefsfile((char*)s.c_str(), direct);}
inline int avistart(string s, treenode winnode, double fps, double uc){return avistart((char*)s.c_str(), winnode, fps, uc);}
inline string pdir(){return (string)pdir_cstr();}
inline string cdir(){return (string)cdir_cstr();}
inline string modeldir() {return (string)modeldir_cstr();}
inline string userdatadir() {return (string)userdatadir_cstr();}
inline string programdatadir() { return programdatadir_cstr(); }
inline string currentfile() {return (string)currentfile_cstr();}
inline int pt(string s){return pt(s.c_str());}
inline int fpt(string s){return fpt(s.c_str());}
inline double excelwritestr(int row, int col, string data){return excelwritestr(row, col, (char*)data.c_str());}
inline char * filebrowse(string ext, string desc, string path){return filebrowse((char*)ext.c_str(), (char*)desc.c_str(), (char*)path.c_str());}
inline string getmodelunitstr(int querytype){return (string)getmodelunitstr_cstr(querytype);}
engine_export const char* getstatestr_cstr(treenode object);
inline string getstatestr(treenode object){return getstatestr_cstr(object);}
inline string getvarstr(treenode object, const char *varname){return getnodestr(var_s(object, varname));}
inline string getvarstr(treenode object, int varrank){return getnodestr(var(object, varrank));}
inline double getvarnum(treenode object, int varrank){return getnodenum(var(object, varrank));}
inline double setvarstr(treenode object, string varname, string val){ return setvarstr(object, (char*)varname.c_str(), (char*)val.c_str());}
inline double setvarstr(treenode object, int varrank, string val){setnodestr(var(object, varrank), val); return 0;}
inline double setvarnum(treenode object, string varname, double val){return setvarnum(object, (char*)varname.c_str(), val);}
inline double setvarnum(treenode object, int varrank, double val){setnodenum(var(object, varrank), val); return 0;}
inline treenode getvarnode(treenode thenode, int therank){return rank(variables(thenode), therank);}
inline double showprogressbar(string text){return showprogressbar((char*)text.c_str());}

engine_export const char* gettableheader_cstr(const char* tablename, int roworcol, int rowcolnr);
engine_export const char*  gettableheader_cstr(int tablename, int roworcol, int rowcolnr);
engine_export const char*  gettableheader_cstr(treenode tablename, int roworcol, int rowcolnr);
inline string gettableheader(treenode table, int roworcol, int rowcolnr){ return gettableheader_cstr(table, roworcol, rowcolnr); }
inline string gettableheader(string table, int roworcol, int rowcolnr){return gettableheader_cstr(table.c_str(), roworcol, rowcolnr);}
inline string gettableheader(int table, int roworcol, int rowcolnr){return gettableheader_cstr(table, roworcol, rowcolnr);}
engine_export void settableheader(treenode table, int roworcol, int rowcolnr, const char* str);
inline int settableheader(treenode table, int roworcol, int rowcolnr, string value){settableheader(table, roworcol, rowcolnr, value.c_str()); return 1;}
inline int settableheader(string table, int roworcol, int rowcolnr, string value){return settableheader(reftable(table), roworcol, rowcolnr, value);}
inline int settableheader(int table, int roworcol, int rowcolnr, string value){return settableheader(reftable(table), roworcol, rowcolnr, value);}

engine_export int gettablerows(treenode table);
visible int gettablerows(const char* table);
inline int gettablerows(string table){return gettablerows(table.c_str());}
engine_export int gettablerows(int table);

inline double settablesize(string table,int nrows,int ncols, int type = 0, int overwrite = 0){return settablesize((char*)table.c_str(), nrows, ncols, type, overwrite);}

visible double importtable(treenode, const char * table, int usetopgrey = 0, int useleftgrey = 0);
visible double exporttable(treenode, const char * table, int usetopgrey = 0, int useleftgrey = 0);

inline double clearglobaltable(string table){return clearglobaltable((char*)table.c_str());}

inline double sorttable(string table, int col){return sorttable((char*)table.c_str(), col);}

engine_export int gettablecols(treenode table);
visible int gettablecols( const char* globaltablename);
inline int gettablecols(string table) { return gettablecols(table.c_str()); }
engine_export int gettablecols(int table);

inline int makearray(int size){return size;}

inline Variant executestring(const string& str, treenode c = NULL, treenode i = NULL, const Variant& data = Variant())
{
	return executestring((char*)str.c_str(), c, i, data);
}

inline size_t maintenance(int command) { return maintenance(command, 0); }
inline int EX(const char* T) { return EX(T, 0); }

inline double drawtext(treenode  windownode, string text, double x, double y, double z, double sx=1, double sy=1, double sz=1, 
					   double rx=0, double ry=0, double rz=0, double red=0, double green=0, double blue=0, double alpha=1)
	{return drawtext(windownode, (char*)text.c_str(), x, y, z, sx, sy, sz, rx, ry, rz, red, green, blue, alpha);}

inline TreeNode* createcopy(TreeNode* classobject, TreeNode* instancecontainer) { return createcopy(classobject, instancecontainer, 0); }

engine_export treenode selectedobject(treenode target, int reset = 0);

inline string stringreplace(string text, const string& searchstr, const string& repstr)
{
	for(size_t pos = text.find(searchstr,0); 
		pos != string::npos && pos < text.size(); 
		pos = text.find(searchstr,pos))
	{
		text = text.replace(pos, searchstr.size(), repstr);
		pos += repstr.size();
	}
	return text;
}

inline string documentsdir(){return documentsdir_cstr();}

inline double excelopen(string a) { return excelopen((char*)a.c_str()); }
inline double excelsetsheet(string a) { return excelsetsheet((char*)a.c_str()); }

inline int fileexists(string a){return fileexists(a.c_str());}

inline int showhtmlhelp(string path){return showhtmlhelp((char*)path.c_str());}

visible double fileopen(const char* filename, const char* mode = NULL);
inline string filereadline() {return (string)filereadline_cstr();}
inline void setviewtext(treenode target, string text){return setviewtext(target, text.c_str());}
inline double addviewtext(treenode target, string text){return addviewtext(target, text.c_str());}
inline int dbsqlquery(string query, int flags = 0){return dbsqlquery((char*)query.c_str(), flags);}
inline int dbopen(string dbname, string command, int tablemode, int loginprompt = 0){return dbopen((char*)dbname.c_str(), (char*)command.c_str(), tablemode, loginprompt);}
inline int dbusername(string username, string password){return dbusername((char*)username.c_str(),(char*)password.c_str());}

inline char* stringtoken(char* token, string delimit){return stringtoken(token, (char*)delimit.c_str());}
inline char* stringtoken(string token, string delimit){return stringtoken((char*)token.c_str(), (char*)delimit.c_str());}

inline double clientconnect(int skt, string hostname, int port){return clientconnect(skt, (char*)hostname.c_str(), port);}
inline string clientreceive(int skt, int BufSize, int NoBlock)
{
	int mybufsize = BufSize;
	if(mybufsize <= 0) mybufsize = 10000;
	char* mybuf = (char*)malloc(mybufsize + 1);
	mybuf[0] = 0;
	clientreceive(skt, mybuf, mybufsize + 1, NoBlock);
	string mystr(mybuf);
	free(mybuf);
	return mystr;
}
inline double clientsend(int skt, string Msg){return clientsend(skt, (char*)Msg.c_str(), Msg.length()+1);}

inline string serverreceive(int skt, int BufSize, int NoBlock)
{
	int mybufsize = BufSize;
	if(mybufsize <= 0) mybufsize = 10000;
	char* mybuf = (char*)malloc(mybufsize + 1);
	mybuf[0] = 0;
	serverreceive(skt, mybuf, mybufsize + 1, NoBlock);
	string mystr(mybuf);
	free(mybuf);
	return mystr;
}
inline double serversend(int skt, string Msg){return serversend(skt, (char*)Msg.c_str(), Msg.length()+1);}

inline int stringsearch(const string& str, const string& substr, int startpos){return stringsearch((char*)str.c_str(), (char*)substr.c_str(), startpos);}
inline int stringsearch(const string& str, const string& substr, int startpos, int flags){return stringsearch((char*)str.c_str(), (char*)substr.c_str(), startpos, flags);}

using std::fabs;
inline int fabs(int val){return (int)std::fabs((double)val);}

#ifdef _WINDOWS
visible int setstate(treenode obj, int statenr);
#else
engine_export int setstate(treenode obj, int statenr);
#endif
engine_export int setstate(treenode obj, int statenr, int profilenr);
engine_export int setstate(treenode obj, int statenr, const char* profilename);
engine_export int setstate(treenode obj, int statenr, treenode profile);

visible int addbundlefield(treenode x, const char* fieldname, int type, int maxstrsize = 0);
visible int setbundlevalue(treenode x, int entrynr, const char* fieldname, double val);
engine_export int setbundlevalue(treenode x, int entrynr, int fieldnr, double val);
engine_export int setbundlevalue(treenode x, int entrynr, const char* fieldname, const char* val);
engine_export int setbundlevalue(treenode x, int entrynr, int fieldnr, const char* val);

engine_export Variant getbundlevalue(treenode x, int entrynr, const char* fieldname);
engine_export Variant getbundlevalue(treenode x, int entrynr, int fieldnr);

engine_export Variant setticker(treenode x, double ticksPerSecond);

visible double importdataset(treenode, const char* table, int format);
visible double exportdataset(treenode, const char* table, int format, const char* wrOption = "w");

inline int aggregateundorecords(TreeNode* view, const char* description, int id1, int id2, int id3 = 0, int id4 = 0, int id5 = 0, int id6 = 0, int id7 = 0)
	{ return aggregateundorecords(view, description, id1, id2, id3, id4, id5, id6, id7, 0); }


engine_export Variant $iter(int index);
inline Variant getqueryvalue(int row, const std::string& colName) {return getqueryvalue(row, (char*)colName.c_str());}

inline int lladd(TreeNode* x, TreeNode* toadd) { return lladd((TreeNodeListHead*)x, toadd); }
inline TreeNode* llinsert(TreeNode* node, TreeNode* container, TreeNode* newTreeNode) { return llinsert((TreeNodeListHead*)node, container, newTreeNode); }
inline void llremove(TreeNode* owner, TreeNode* x) { return llremove((TreeNodeListHead*)owner, x); }

inline double _parqty(CallPoint* callpoint) { return parqty(callpoint); }

#if defined COMPILING_FLEXSIM_CONTENT || defined COMPILING_MODULE_DLL
	engine_export treenode createevent(FlexSimEvent* e);
	visible TreeNode* getcorecommandfunction(int index);
	visible portinfo inobjectinfo(TreeNode*, int);
	visible portinfo outobjectinfo(TreeNode*, int);
	visible treenode nodeaddcouplingdata(treenode target, CouplingDataType* cdt, int bind);
	visible treenode nodeaddsimpledata(treenode target, SimpleDataType* sdt, int bind);
	visible treenode nodedetachsimpledata(treenode target);
	visible Variant fglInfo(int op, treenode view);
#else
	visible int     contentunder(TreeNode*, int flags = 0);
	inline double   dispatchcoordinatedtasksequence(treenode tasksequence, treenode dispatcher = NULL){return dispatchcoordinatedtasksequencealias(tasksequence, dispatcher);}
	inline double   dispatchtasksequence(treenode tasksequence, treenode dispatcher = NULL){return dispatchtasksequencealias(tasksequence, dispatcher);}
	inline double   gettreedrawposition(treenode object, treenode roottree, int* cury = NULL, int increment = 0){return gettreedrawpositionalias(object,roottree,cury,increment);}
	inline int      insertdeallocatetask(treenode tasksequence, int executerkey, int noblock = 0){return insertdeallocatetaskalias(tasksequence,executerkey,noblock);}
	inline int      insertproxytask(treenode tasksequence, unsigned int executerkey, unsigned int  type, treenode involved1, treenode involved2, double var1, double var2, double var3, double var4){return insertproxytaskalias1(tasksequence,executerkey,type,involved1,involved2,var1,var2,var3,var4);}
	inline int      insertproxytask(treenode tasksequence, unsigned int executerkey, unsigned int  type, treenode involved1){return insertproxytaskalias2(tasksequence,executerkey,type,involved1);}
	inline int      insertproxytask(treenode tasksequence, unsigned int executerkey, unsigned int  type, treenode involved1, int involved2, double var1, double var2, double var3, double var4){return insertproxytaskalias3(tasksequence,executerkey,type,involved1,involved2,var1,var2,var3,var4);}
	inline int      insertproxytask(treenode tasksequence, unsigned int executerkey, unsigned int  type){return insertproxytaskalias4(tasksequence,executerkey,type);}
	inline int      insertproxytask(treenode tasksequence, unsigned int executerkey, unsigned int  type, int involved1, treenode involved2, double var1, double var2, double var3, double var4){return insertproxytaskalias5(tasksequence,executerkey,type,involved1,involved2,var1,var2,var3,var4);}
	inline int      insertproxytask(treenode tasksequence, unsigned int executerkey, unsigned int  type, int involved1){return insertproxytaskalias6(tasksequence,executerkey,type,involved1);}
	inline int      insertproxytask(treenode tasksequence, unsigned int executerkey, unsigned int  type, int involved1, int involved2, double var1, double var2, double var3, double var4){return insertproxytaskalias7(tasksequence,executerkey,type,involved1,involved2,var1,var2,var3,var4);}
	inline treenode inserttask(treenode tasksequence,  unsigned int  type, treenode involved1, treenode involved2 , double var1 , double var2 , double var3 , double var4){return inserttaskalias(tasksequence,type,involved1,involved2,var1,var2,var3,var4);}
	visible double  profileevents(int removedevents = 0);
	inline double   receiveitem(treenode station, int port){return receiveitem_alias2(station,port);}
	inline double   receiveitem(treenode station){return receiveitem_alias1(station);}
	inline double   releaseitem(treenode station, int port){return releaseitem_alias2(station,port);}
	inline double   releaseitem(treenode station){return releaseitem_alias1(station);}
	inline double   transportincomplete (treenode object, treenode item, int portnumber = 0, treenode transporter = NULL){return transportincompletealias (object,item,portnumber,transporter);}
	inline double   transportoutcomplete(treenode object, treenode item, int portnumber = 0, treenode transporter = NULL){return transportoutcompletealias(object,item,portnumber,transporter);}
	visible double  validatename(treenode current, int isview = 0, treenode obj = NULL);
#endif

// lambdas only work on visual studio 2010 or later
#if _MSC_VER >= 1600
	template<class NumGetter>
	double cpp_getdatastat(int stat, int nr, NumGetter getter, double p1, double p2, double p3)
	{
		static double * buffer = 0;
		static int bufferSize = 0;
		if (!buffer || bufferSize < nr) {
			if (buffer)
				delete [] buffer;
			bufferSize = nr * 2;
			buffer = new double[bufferSize];
		}
		for (int i = 0; i < nr; i++)
			buffer[i] = getter(i + 1);
		return getdatastat(
			stat, 
			nr, 
			buffer, 
			p1, 
			p2, 
			p3);
	}

	#define getdatastat(stat, nr, func, p1, p2, p3) \
			(objectexists((treenode)(size_t)nr) \
				? getdatastat(stat, (treenode)(size_t)nr, (treenode)(size_t)func, p1, p2, p3) \
				: cpp_getdatastat(stat, (int)(size_t)nr, [&](int count) -> double {return (double)func;}, p1, p2, p3))
#endif

engine_export double getstat(TreeNode* obj, const char* statName, int flag, const Variant& p1 = Variant(), const Variant& p2 = Variant(), const Variant& p3 = Variant());

engine_export Variant applicationcommand(const char* cmd, n10varsdefaultinterface);

engine_export Variant getlabel(treenode object, const char* labelName);
inline Variant getlabel(treenode object, const string& labelName) { return getlabel(object, labelName.c_str()); }
engine_export Variant getlabel(treenode object, int labelRank);
engine_export Variant getlabel(treenode object, Variant labelName);

engine_export void setlabel(treenode object, const char* labelName, Variant toVal);
inline void setlabel(treenode object, const string& labelName, Variant toVal) {return setlabel(object, labelName.c_str(), toVal);}
engine_export void setlabel(treenode object, int labelRank, Variant toVal);
engine_export void setlabel(treenode object, Variant labelName, Variant toVal);

engine_export Variant listpush(const char* listName, const Variant& involved);
inline Variant listpush(const std::string& listName, const Variant& involved) {return listpush(listName.c_str(), involved);}
engine_export Variant listpush(const char* listName, const Variant& involved, const Variant& partitionId, const Variant& p1 = Variant(), const Variant& p2 = Variant(),
                                            const Variant& p3 = Variant(), const Variant& p4 = Variant(), const Variant& p5 = Variant(), const Variant& p6 = Variant(),
                                            const Variant& p7 = Variant(), const Variant& p8 = Variant());
inline Variant listpush(const std::string& listName, const Variant& involved, const Variant& partitionId, const Variant& p1 = Variant(), const Variant& p2 = Variant(),
                                            const Variant& p3 = Variant(), const Variant& p4 = Variant(), const Variant& p5 = Variant(), const Variant& p6 = Variant(),
                                            const Variant& p7 = Variant(), const Variant& p8 = Variant())
					{ return listpush(listName.c_str(), involved, partitionId, p1, p2, p3, p4, p5, p6, p7, p8); }

engine_export Variant listpush(treenode list, const Variant& involved);
engine_export Variant listpush(treenode list, const Variant& involved, const Variant& partitionId, const Variant& p1 = Variant(), const Variant& p2 = Variant(),
                                            const Variant& p3 = Variant(), const Variant& p4 = Variant(), const Variant& p5 = Variant(), const Variant& p6 = Variant(),
                                            const Variant& p7 = Variant(), const Variant& p8 = Variant());

engine_export void listaddlistener(treenode entry, treenode callbackNode, const Variant& p1 = Variant(), const Variant& p2 = Variant(), const Variant& p3 = Variant(), 
	const Variant& p4 = Variant(), const Variant& p5 = Variant(), const Variant& p6 = Variant(), const Variant& p7 = Variant(), 
	const Variant& p8 = Variant(), const Variant& p9 = Variant(), const Variant& p10 = Variant());
engine_export treenode listbackorders(TreeNode* listNode, const Variant& partitionId = Variant());
engine_export treenode listentries(TreeNode* listNode, const Variant& partitionId = Variant());
engine_export Variant listpull(TreeNode* listNode, TreeNode* cachedQuery, int requestNum = 1, int requireNum = 1, const Variant& puller = Variant(), const Variant& partitionId = Variant(), int flags = 0);
engine_export Variant listpull(TreeNode* listNode, const char* query, int requestNum = 1, int requireNum = 1, const Variant& puller = Variant(), const Variant& partitionId = Variant(), int flags = 0);
engine_export Variant listpull(const char* listName, TreeNode* cachedQuery, int requestNum = 1, int requireNum = 1, const Variant& puller = Variant(), const Variant& partitionId = Variant(), int flags = 0);
engine_export Variant listpull(const char* listName, const char* query, int requestNum = 1, int requireNum = 1, const Variant& puller = Variant(), const Variant& partitionId = Variant(), int flags = 0);
engine_export void listremove(TreeNode* entryOrBackOrder);
engine_export treenode globallist(const char* listName);
engine_export treenode globallist(int listRank);
engine_export double drawobject(treenode windownode, int shape, int texture, int animation = 0);
engine_export Variant getmodelunit(int querytype);
engine_export Variant convert(const Variant& value, const Variant& from, const Variant& to);

#if defined COMPILING_FLEXSIM_CONTENT || defined COMPILING_MODULE_DLL
__declspec(dllimport) void sql_buildquery(TreeNode* queryNode, char* query, SqlDataSource* d);
__declspec(dllimport) int sql_doquery(TreeNode* queryNode, bool doOrderby);
__declspec(dllimport) void sql_sortresult(TreeNode* queryNode, SqlDataSource* d, int begin, int end);
#endif

inline char* _parstr(int index, CallPoint * callpoint) { return (char*)__parstr(index, callpoint); }
visible int undo(treenode view = 0);
visible int redo(treenode view = 0);
engine_export Variant listenerinfo(int info, const Variant& p1 = Variant(), const Variant& p2 = Variant());

visible int gettableviewselection(treenode view, int cell);

engine_export treenode delayednodefunction(treenode theNode, double timeOffset, n10varsdefaultinterface);
engine_export Variant nodefunction(treenode node, n10varsdefaultinterface);
engine_export Variant nodefunctionasevent(treenode thenode, FLEXSIMINTERFACE);
engine_export TreeNode* nodefunctionlisten(treenode theNode, treenode relayNode, int flags, n10varsdefaultinterface);
engine_export Variant sendmessage(treenode node, treenode associated, n10varsdefaultinterface);
engine_export Variant function_s(treenode node, const char * name, n10varsdefaultinterface);
engine_export Variant function_n(treenode node, int index, n10varsdefaultinterface);
engine_export Variant userfunction_s(treenode node, const char * name, n10varsdefaultinterface);
engine_export Variant userfunction_n(treenode node, int index, n10varsdefaultinterface);
engine_export int addbundleentry(treenode x);
engine_export int addbundleentry(treenode x, const Variant& n1, const Variant& n2 = Variant(), const Variant& n3 = Variant(), const Variant& n4 = Variant(), const Variant& n5 = Variant(), 
				const Variant& n6 = Variant(), const Variant& n7 = Variant(), const Variant& n8 = Variant(), const Variant& n9 = Variant(), const Variant& n10 = Variant());
engine_export int addbundleentry(treenode x, const Variant& n1, const Variant& n2, const Variant& n3, const Variant& n4, const Variant& n5,
	const Variant& n6, const Variant& n7, const Variant& n8, const Variant& n9, const Variant& n10, const Variant& n11,
	const Variant& n12 = Variant(), const Variant& n13 = Variant(), const Variant& n14 = Variant(), const Variant& n15 = Variant(), const Variant& n16 = Variant(), const Variant& n17 = Variant(),
	const Variant& n18 = Variant(), const Variant& n19 = Variant(), const Variant& n20 = Variant(), const Variant& n21 = Variant(), const Variant& n22 = Variant(), const Variant& n23 = Variant(), 
	const Variant& n24 = Variant(), const Variant& n25 = Variant(), const Variant& n26 = Variant(), const Variant& n27 = Variant(), const Variant& n28 = Variant(), const Variant& n29 = Variant(), 
	const Variant& n30 = Variant());

engine_export int __eventcode__(CallPoint*);
engine_export Variant __eventdata__(CallPoint*);
engine_export Variant __i__(CallPoint*);
engine_export Variant __c__(CallPoint*);

visible TreeNode* setcenter(TreeNode*, double, double, double);
visible TreeNode* setloc(TreeNode*, double, double, double);
engine_export TreeNode* setloc(TreeNode*, double, double, double, double, double, double);

visible char* excelrangeread(char *name, int row, int col);
engine_export int excelrangeread(treenode target, int row1, int col1, int row2, int col2, unsigned char flags = 0);

visible int excelrangewrite(char* name, char* value, int row, int col);
engine_export int excelrangewrite(treenode source, int row, int col, unsigned char flags = 0);

engine_export treenode trackedvariable(const char* listName);
inline treenode trackedvariable(const std::string& str) { return trackedvariable(str.c_str()); }
engine_export treenode inittrackedvariable(treenode theNode, int type, double startValue, int flags);

engine_export int getsystemmetric(int metric, Window win);
engine_export Variant callwebscriptmethod(treenode view, const char* id, const char* name, ...);

visible void fglMultMatrix(float m00, float m01, float m02, float m03, float m04, float m05, float m06, float m07, float m08, float m09, float m10, float m11, float m12, float m13, float m14, float m15);
engine_export void fglMultMatrix(const float* matrix);
visible void fglLoadMatrix(float m00, float m01, float m02, float m03, float m04, float m05, float m06, float m07, float m08, float m09, float m10, float m11, float m12, float m13, float m14, float m15);
engine_export void fglLoadMatrix(const float* matrix);
engine_export void fglColorMaterial(int colorMaterial);
engine_export int fglGetUniformLocation(int program, const char* name);
engine_export void fglUniform(int location, float value);
engine_export int fglGetAttribLocation(int program, const char* name);
engine_export void fglVertexAttrib(int location, const Vec4f& vec);
engine_export void fglVertexAttrib(int location, const Vec3f& vec);
engine_export void fglVertexAttrib(int location, const Vec2f& vec);
engine_export void fglVertexAttrib(int location, float val);
engine_export void autoloadallmedia(treenode obj);
visible int autoloadallmedia();

engine_export int print();
engine_export int print(const Variant&);
engine_export int print(const Variant&, const Variant&);
engine_export int print(const Variant&, const Variant&, const Variant&);
engine_export int print(const Variant&, const Variant&, const Variant&, const Variant&);
engine_export int print(const Variant&, const Variant&, const Variant&, const Variant&, const Variant&);
engine_export int print(const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&);
engine_export int print(const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&);
engine_export int print(const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&);
engine_export int print(const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&);
engine_export int print(const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&);
engine_export int print(const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&,
	const Variant&);
engine_export int print(const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&,
	const Variant&, const Variant&);
engine_export int print(const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&,
	const Variant&, const Variant&, const Variant&);
engine_export int print(const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&,
	const Variant&, const Variant&, const Variant&, const Variant&);
engine_export int print(const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&,
	const Variant&, const Variant&, const Variant&, const Variant&, const Variant&);
engine_export int print(const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&,
	const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&);
engine_export int print(const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&,
	const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&);
engine_export int print(const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&,
	const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&);
engine_export int print(const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&,
	const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&);
engine_export int print(const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&,
	const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&);

engine_export Variant shapeinfo(int info, const Variant& p1 = Variant(), const Variant& p2 = Variant(), const Variant& p3 = Variant());
engine_export void rotationproject(treenode originSpace, double rx, double ry, double rz, treenode ontoSpace, double* rotationsOut);
visible int getrunstate();
engine_export int getrunstate(int checkProcessingEvent);
engine_export int setcursor(int cursorID, int forgetCount = 0);
}

#endif