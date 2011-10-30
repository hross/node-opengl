var SDL = require( '../../node-sdl/sdl' );
var GL = require('../opengl');

// initialize SDL video components
SDL.init( SDL.INIT.VIDEO );
//SDL.IMG.init( 0 );

// set up OpenGL
SDL.GL.setAttribute(SDL.GL.DOUBLEBUFFER, 1);
SDL.GL.setAttribute(SDL.GL.DEPTH_SIZE, 16);
SDL.GL.setAttribute(SDL.GL.RED_SIZE, 8);
SDL.GL.setAttribute(SDL.GL.GREEN_SIZE, 8);
SDL.GL.setAttribute(SDL.GL.BLUE_SIZE, 8);
SDL.GL.setAttribute(SDL.GL.ALPHA_SIZE, 8);

// create a window to draw in
// SDL.SURFACE.OPENGL | SDL.SURFACE.FULLSCREEN
var screen = SDL.setVideoMode( 640, 480, 32, SDL.SURFACE.OPENGL);

initialize();

function initialize() {
  // set up light sources 
  GL.light(GL.LIGHT0, GL.DIFFUSE, [1,0,0,1]);
  GL.light(GL.LIGHT0, GL.POSITION, [1,1,1,0]);
  GL.enable(GL.LIGHT0);
  GL.enable(GL.LIGHTING);

  // use depth buffering for hidden surface elmination
  GL.enable(GL.DEPTH_TEST);

  // set up the view of the cube
  GL.matrixMode(GL.PROJECTION);
  GL.perspective(40, /* field of view in degrees */
                 1, /*aspect ratio */
                 1, /* z near */
                 10); /* z var */


  GL.matrixMode(GL.MODELVIEW);
  GL.lookAt(0, 0, 5, /* eye is at 0,0,5 */
                           0, 0, 0, /* center is at 0,0,0 */
                           0, 1, 0); /* up is in +Y direction */

  /* adjust cube position */
  GL.translate(0, 0, -1);
  GL.rotate(60, 1, 0, 0);
  GL.rotate(-20, 0, 0, 1);
}

function redraw() {
  // start with a clear screen
  GL.clear(GL.COLOR_BUFFER_BIT | GL.DEPTH_BUFFER_BIT);

  // draw the box  
  drawBox();

  // swap the buffers
  SDL.GL.swapBuffers();
}


function drawBox() {

  // rotate the cube each time we draw so it animates
  GL.rotate(-5, 0, 0, 1);

  GL.begin(GL.QUADS);

  // top
  GL.vertex3([0, 0, 0]);
  GL.vertex3([0, 0, -1]);
  GL.vertex3([-1, 0, -1]);
  GL.vertex3([-1, 0, 0]);

  // front
  GL.vertex3([0, 0, 0]);
  GL.vertex3([-1, 0, 0]);
  GL.vertex3([-1, -1, 0]);
  GL.vertex3([0, -1, 0]);

  // right
  GL.vertex3([0, 0, 0]);
  GL.vertex3([0, -1, 0]);
  GL.vertex3([0, -1, -1]);
  GL.vertex3([0, 0, -1]);

  // left
  GL.vertex3([-1, 0, 0]);
  GL.vertex3([-1, 0, -1]);
  GL.vertex3([-1, -1, -1]);
  GL.vertex3([-1, -1, 0]);

  // bottom
  GL.vertex3([0, 0, 0]);
  GL.vertex3([0, -1, -1]);
  GL.vertex3([-1, -1, -1]);
  GL.vertex3([-1, -1, 0]);

  // back
  GL.vertex3([0, 0, 0]);
  GL.vertex3([-1, 0, -1]);
  GL.vertex3([-1, -1, -1]);
  GL.vertex3([0, -1, -1]);

  GL.end();
}

// quit 
function quit ( exitCode ) {
  process.exit( exitCode );
}

/** SDL key event handlers **/
SDL.events.on('QUIT', function(evt) {
  console.log("Quit pushed.");
  quit(0);
});

SDL.events.on('KEYDOWN', function (evt) {
  console.log("Keydown: " + JSON.stringify(evt));

  // Ctrl+Q
  if (evt.sym && (113 == evt.sym) && evt.mod && (64 == evt.mod)) {
    quit(0); 
  }
});

SDL.events.on( 'tick', function ( d ) {
  redraw();
});
