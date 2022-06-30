using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MathClasses
{
    public struct Colour
    {
        // this will store four bytes representing RGBA in the most to last significant bytes
        public UInt32 colour;

        //constructs the Colour variable
        public Colour(byte r, byte g, byte b, byte a)
        {
            colour = 0;
            red = r;
            green = g;
            blue = b;
            alpha = a;

        }

        //establishes the 'red' bit in the Colour variable
        public byte red
        {
            get { return (byte)((colour >> 24) & 0xff); }
            set { colour = (colour & 0x00ffffff) | ((UInt32)value << 24); }
        }

        //establishes the 'green' bit in the Colour variable
        public byte green
        {
            get { return (byte)((colour >> 16) & 0xff); }
            set { colour = (colour & 0xff00ffff) | ((UInt32)value << 16); }
        }

        //establishes the 'blue' bit in the Colour variable
        public byte blue
        {
            get { return (byte)((colour >> 8) & 0xff); }
            set { colour = (colour & 0xffff00ff) | ((UInt32)value << 8); }
        }

        //establishes the 'alpha' bit in the Colour variable
        public byte alpha
        {
            get { return (byte)((colour >> 0) & 0xff); }
            set { colour = (colour & 0xffffff00) | ((UInt32)value << 0); }
        }
    }
}
