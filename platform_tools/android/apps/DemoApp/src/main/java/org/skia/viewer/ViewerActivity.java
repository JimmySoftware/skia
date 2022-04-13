/*
 * Copyright 2015 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

package org.skia.viewer;

import android.app.Activity;
import android.content.res.Configuration;
import android.os.Bundle;
import android.support.v4.widget.DrawerLayout;
import android.support.v7.app.ActionBarDrawerToggle;
import android.view.KeyEvent;
import android.view.Menu;
import android.view.MenuInflater;
import android.view.MenuItem;
import android.view.MotionEvent;
import android.view.Surface;
import android.view.SurfaceHolder;
import android.view.SurfaceView;
import android.view.View;
import android.widget.ListView;
import android.widget.Toast;
import android.view.GestureDetector;
import android.util.Log;
import android.util.DisplayMetrics;
import android.view.Window;
import android.view.WindowManager;

public class ViewerActivity
        extends Activity implements SurfaceHolder.Callback, View.OnTouchListener, GestureDetector.OnGestureListener {
    //private static final float FLING_VELOCITY_THRESHOLD = 1000;
    private static final int SWIPE_MIN_DISTANCE = 120;
    private static final int SWIPE_THRESHOLD_VELOCITY = 200;

    //private DrawerLayout mDrawerLayout;
    //private ActionBarDrawerToggle mDrawerToggle;
    //private ListView mDrawerList;
    //private StateAdapter mStateAdapter;

    private ViewerApplication mApplication;
    private GestureDetector gDetector;

    private native void onSurfaceCreated(long handle, Surface surface, int dpi);
    private native void onSurfaceChanged(long handle, Surface surface, int dpi);
    private native void onSurfaceDestroyed(long handle);
    private native void onKeyPressed(long handle, int keycode);
    private native void onTouched(long handle, int owner, int state, float x, float y);
    private native void onFlinged(long handle, int state);
    private native void onUIStateChanged(long handle, String stateName, String stateValue);

    /*
    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        MenuInflater inflater = getMenuInflater();
        inflater.inflate(R.menu.title, menu);
        return true;
    }
    
    
    @Override
    public boolean onTouchEvent(MotionEvent me) {
        Log.d("JIMMY","onTouchEvent: ");
        return gDetector.onTouchEvent(me);
    }  
    */  

    @Override
    public boolean onDown(MotionEvent e) {
        // TODO Auto-generated method stub
        //Toast.makeText(this,"onDown",Toast.LENGTH_LONG).show();
        return false;
    }
    
    @Override
    public boolean onFling(MotionEvent e1, MotionEvent e2, float velocityX, float velocityY) {
        if(e1.getX() - e2.getX() > SWIPE_MIN_DISTANCE && Math.abs(velocityX) > SWIPE_THRESHOLD_VELOCITY) {
            //Toast.makeText(this,"onFling Left",Toast.LENGTH_SHORT).show();
            onFlinged(mApplication.getNativeHandle(), 4);
            return false; // Right to left
        }  else if (e2.getX() - e1.getX() > SWIPE_MIN_DISTANCE && Math.abs(velocityX) > SWIPE_THRESHOLD_VELOCITY) {
            //Toast.makeText(this,"onFling Right",Toast.LENGTH_SHORT).show();
            onFlinged(mApplication.getNativeHandle(), 3);
            return false; // Left to right
        }
        /*
        if(e1.getY() - e2.getY() > SWIPE_MIN_DISTANCE && Math.abs(velocityY) > SWIPE_THRESHOLD_VELOCITY) {
            return false; // Bottom to top
        }  else if (e2.getY() - e1.getY() > SWIPE_MIN_DISTANCE && Math.abs(velocityY) > SWIPE_THRESHOLD_VELOCITY) {
            return false; // Top to bottom
        }
        */
        return false;
    }    
    
    @Override
    public void onLongPress(MotionEvent e) {
        // TODO Auto-generated method stub
        //Toast.makeText(this,"onLongPress",Toast.LENGTH_LONG).show();
    }
    
    @Override
    public boolean onScroll(MotionEvent e1, MotionEvent e2, float distanceX,
            float distanceY) {
        // TODO Auto-generated method stub
        //Toast.makeText(this,"onScroll",Toast.LENGTH_LONG).show();
        return false;
    }
    
    @Override
    public void onShowPress(MotionEvent e) {
        // TODO Auto-generated method stub
        //Toast.makeText(this,"onShowPress",Toast.LENGTH_LONG).show();
    }
    
    @Override
    public boolean onSingleTapUp(MotionEvent e) {
        // TODO Auto-generated method stub`enter code here`
        //Toast.makeText(this,"onSingleTapUp",Toast.LENGTH_SHORT).show();
        return false;
    }
    
    @Override
    public boolean dispatchTouchEvent(MotionEvent e)
    {
        super.dispatchTouchEvent(e);
        return gDetector.onTouchEvent(e);
    }

    /*
    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        // Pass the event to ActionBarDrawerToggle, if it returns
        // true, then it has handled the app icon touch event
        if (mDrawerToggle != null && mDrawerToggle.onOptionsItemSelected(item)) {
            return true;
        }

        switch (item.getItemId()) {
            case R.id.action_left:
                onKeyPressed(mApplication.getNativeHandle(), KeyEvent.KEYCODE_SOFT_LEFT);
                return true;
            case R.id.action_right:
                onKeyPressed(mApplication.getNativeHandle(), KeyEvent.KEYCODE_SOFT_RIGHT);
                return true;
            default:
                return super.onOptionsItemSelected(item);
        }
    }
    */

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        requestWindowFeature(Window.FEATURE_NO_TITLE);
        
        View decorView = getWindow().getDecorView();
        // Hide both the navigation bar and the status bar.
        // SYSTEM_UI_FLAG_FULLSCREEN is only available on Android 4.1 and higher, but as
        // a general rule, you should design your app to hide the status bar whenever you
        // hide the navigation bar.
        int uiOptions = View.SYSTEM_UI_FLAG_HIDE_NAVIGATION; //View.SYSTEM_UI_FLAG_FULLSCREEN; // | 
        decorView.setSystemUiVisibility(uiOptions);    
        
        
        
        //Remove title bar
        //this.requestWindowFeature(Window.FEATURE_NO_TITLE);

        //Remove notification bar
        //this.getWindow().setFlags(WindowManager.LayoutParams.FLAG_FULLSCREEN, WindowManager.LayoutParams.FLAG_FULLSCREEN);

        setContentView(R.layout.activity_main);

        gDetector = new GestureDetector(this, this);

        
        SurfaceView surfaceView = (SurfaceView) findViewById(R.id.surfaceView);
        surfaceView.getHolder().addCallback(this);
        surfaceView.setOnTouchListener(this);
        

        /*
        mDrawerLayout = (DrawerLayout) findViewById(R.id.drawerLayout);
        if (mDrawerLayout != null) { // xlarge-land has no drawer layout (drawer is always open)
            mDrawerToggle = new ActionBarDrawerToggle(this, mDrawerLayout,
                    R.string.drawer_open, R.string.drawer_close);
            mDrawerLayout.addDrawerListener(mDrawerToggle);
            getActionBar().setDisplayHomeAsUpEnabled(true);
            getActionBar().setHomeButtonEnabled(true);
        }

        mDrawerList = (ListView) findViewById(R.id.leftDrawer);
        mStateAdapter = new StateAdapter(this);
        mDrawerList.setAdapter(mStateAdapter);
        */

        mApplication = (ViewerApplication) getApplication();
        mApplication.setViewerActivity(this);
    }

    @Override
    public void onResume(){
        super.onResume();

        View decorView = getWindow().getDecorView();
        // Hide both the navigation bar and the status bar.
        // SYSTEM_UI_FLAG_FULLSCREEN is only available on Android 4.1 and higher, but as
        // a general rule, you should design your app to hide the status bar whenever you
        // hide the navigation bar.
        int uiOptions = View.SYSTEM_UI_FLAG_HIDE_NAVIGATION; //View.SYSTEM_UI_FLAG_FULLSCREEN; // | 
        decorView.setSystemUiVisibility(uiOptions); 
    }    
    
    @Override
    public void onWindowFocusChanged(boolean hasFocus) {         
        super.onWindowFocusChanged(hasFocus);

        View decorView = getWindow().getDecorView();
        // Hide both the navigation bar and the status bar.
        // SYSTEM_UI_FLAG_FULLSCREEN is only available on Android 4.1 and higher, but as
        // a general rule, you should design your app to hide the status bar whenever you
        // hide the navigation bar.
        int uiOptions = View.SYSTEM_UI_FLAG_HIDE_NAVIGATION; //View.SYSTEM_UI_FLAG_FULLSCREEN; // | 
        decorView.setSystemUiVisibility(uiOptions);   

    }    

    @Override
    protected void onPostCreate(Bundle savedInstanceState) {
        super.onPostCreate(savedInstanceState);
        /*
        if (mDrawerToggle != null) {
            mDrawerToggle.syncState();
        }
        */
    }

    @Override
    public void onConfigurationChanged(Configuration newConfig) {
        super.onConfigurationChanged(newConfig);
        /*
        if (mDrawerToggle != null) {
            mDrawerToggle.onConfigurationChanged(newConfig);
        }
        */
    }

    @Override
    protected void onDestroy() {
        mApplication.setViewerActivity(null);
        super.onDestroy();
    }

    @Override
    public void surfaceCreated(SurfaceHolder holder) {
        if (mApplication.getNativeHandle() != 0) {
            DisplayMetrics metrics = getResources().getDisplayMetrics();
            onSurfaceCreated(mApplication.getNativeHandle(), holder.getSurface(), metrics.densityDpi/160);
        }
    }

    @Override
    public void surfaceChanged(SurfaceHolder holder, int format, int width, int height) {
        if (mApplication.getNativeHandle() != 0) {
            DisplayMetrics metrics = getResources().getDisplayMetrics();
            onSurfaceChanged(mApplication.getNativeHandle(), holder.getSurface(), metrics.densityDpi/160);
        }
    }

    @Override
    public void surfaceDestroyed(SurfaceHolder holder) {
        if (mApplication.getNativeHandle() != 0) {
            onSurfaceDestroyed(mApplication.getNativeHandle());
        }
    }

    @Override
    public boolean onTouch(View v, MotionEvent event) {
        int count = event.getPointerCount();
        for (int i = 0; i < count; i++) {
            final float x = event.getX(i);
            final float y = event.getY(i);
            final int owner = event.getPointerId(i);
            int action = event.getAction() & MotionEvent.ACTION_MASK;
            //Toast.makeText(this,"onTouch",Toast.LENGTH_SHORT).show();
            //onTouched(mApplication.getNativeHandle(), owner, action, x, y);
        }
        return gDetector.onTouchEvent(event);
        //return true;
    }

    /*
    public void setState(String stateJson) {
        mStateAdapter.setState(stateJson);
    }

    public void onStateChanged(String stateName, String stateValue) {
        onUIStateChanged(mApplication.getNativeHandle(), stateName, stateValue);
    }
    */
}
