
//wxDirTraverser 很方便，很好，很强大。

//-------------------------------------------------------------------------
#include <wx/wx.h>
#include <wx/dir.h>
#include <stdio.h>

void walk1()
{
    wxDir dir(_("/tmp"));

    if ( !dir.IsOpened() )
        return;

    wxString filename;
    bool cont = dir.GetFirst(&filename);


    wprintf(L"111:\n");
    while ( cont )
    {
        wprintf(L"%s\n", filename.c_str());
        cont = dir.GetNext(&filename);
    }
}

class wxDirTraverserSimple : public wxDirTraverser
{
public:
    wxDirTraverserSimple(wxArrayString& files) : m_files(files) { }

    virtual wxDirTraverseResult OnFile(const wxString& filename)
    {
        m_files.Add(_("file: ") + filename);
        return wxDIR_CONTINUE;
    }

    virtual wxDirTraverseResult OnDir(const wxString& dirname)
    {
        m_files.Add(_("dir: ") + dirname);
        return wxDIR_CONTINUE;
    }

private:
    wxArrayString& m_files;
};

void walk2()
{
    wxArrayString files;
    wxDirTraverserSimple traverser(files);

    wxDir dir(_("/tmp"));
    dir.Traverse(traverser);

    size_t i;
    wprintf(L"222:\n");
    for ( i = 0; i < files.GetCount(); i++ )
    {
        wprintf(L"%s\n", files[i].c_str());
    }
}

int main()
{
    walk1();
    walk2();
    return 0;
}
//----------------------------

