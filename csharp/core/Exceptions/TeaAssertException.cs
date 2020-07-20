using System;

namespace AlibabaCloud.TeaAssert.Exceptions
{
    public class TeaAssertException : Exception
    {
        public TeaAssertException() : base()
        {

        }

        public TeaAssertException(string message) : base(message)
        {

        }

        public TeaAssertException(string message, Exception innerException) : base(message, innerException)
        {

        }
    }
}
