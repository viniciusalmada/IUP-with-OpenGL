#include <iup/iup.h>
#include <iup/iupgl.h>
#include <GL/glew.h>
#include <cstdio>

int canvas_action_cb(Ihandle* ih, float posx, float posy)
{
  IupGLMakeCurrent(ih);
  glClearColor(1.0f, 0.3f, 0.3f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  IupGLSwapBuffers(ih);

  return IUP_DEFAULT;
}

int redraw_canvas_cb(Ihandle* ih)
{
  IupRedraw(IupGetHandle("canvas"), true);

  return IUP_DEFAULT;
}

int main(int argc, char* argv[])
{
  IupOpen(&argc, &argv);
  IupGLCanvasOpen();

  Ihandle* canvas = IupGLCanvas(nullptr);
  IupSetHandle("canvas", canvas);
  IupSetAttribute(canvas, "EXPAND", "YES");
  IupSetAttribute(canvas, "BORDERS", "NO");
  IupSetCallback(canvas, "ACTION", (Icallback)canvas_action_cb);

  Ihandle* box = IupHbox(canvas, nullptr);

  Ihandle* dlg = IupDialog(box);
  IupSetAttribute(dlg, "SIZE", "400x210");
  IupSetCallback(dlg, "K_s", redraw_canvas_cb);

  IupShowXY(dlg, IUP_CENTER, IUP_CENTER);

  IupRedraw(dlg, true);

  IupMainLoop();

  IupClose();

  return 0;
}