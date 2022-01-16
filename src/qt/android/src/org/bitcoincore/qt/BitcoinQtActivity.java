package org.driyalcore.qt;

import android.os.Bundle;
import android.system.ErrnoException;
import android.system.Os;

import org.qtproject.qt5.android.bindings.QtActivity;

import java.io.File;

public class DRiyalQtActivity extends QtActivity
{
    @Override
    public void onCreate(Bundle savedInstanceState)
    {
        final File driyalDir = new File(getFilesDir().getAbsolutePath() + "/.driyal");
        if (!driyalDir.exists()) {
            driyalDir.mkdir();
        }

        super.onCreate(savedInstanceState);
    }
}
