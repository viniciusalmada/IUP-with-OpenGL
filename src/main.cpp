#include <iup/iup.h>
#include <iup/iupgl.h>

int main(int argc, char* argv[])
{
  IupOpen(&argc, &argv);
  IupGLCanvasOpen();

  Ihandle* canvas = IupGLCanvas(nullptr);
  IupSetAttribute(canvas, "EXPAND", "YES");

  Ihandle* box = IupHbox(canvas, nullptr);

  Ihandle* dlg = IupDialog(box);
  IupSetAttribute(dlg, "SIZE", "400x210");

  IupShowXY(dlg, IUP_CENTER, IUP_CENTER);

  IupRedraw(dlg, true);

  IupMainLoop();

  IupClose();

  return 0;
}