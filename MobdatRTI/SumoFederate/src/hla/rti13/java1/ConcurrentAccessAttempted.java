package hla.rti13.java1;

public class ConcurrentAccessAttempted extends RTIexception
{
	private static final long serialVersionUID = 98121116105109L;
	
	public ConcurrentAccessAttempted( String reason )
	{
		super( reason );
	}

	public ConcurrentAccessAttempted( String reason, int serial )
	{
		super( reason, serial );
	}
	
	public ConcurrentAccessAttempted()
    {
	    super();
    }

    /**
     * @param cause The cause of the exception
     */
    public ConcurrentAccessAttempted( Throwable cause )
    {
	    super( cause );
    }

    /**
     * @param message The message to create the exception with
     * @param cause The cause of the exception
     */
    public ConcurrentAccessAttempted( String message, Throwable cause )
    {
	    super( message, cause );
    }
}
