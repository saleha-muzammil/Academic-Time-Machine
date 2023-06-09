import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;
import java.sql.*;

public class Client11 extends HttpServlet
{
   String s1,s2,s3=""; int j;
   String s4="",s5="",accno;
    
    double amount,i;
    Connection con;
  public void init(ServletConfig sc)throws ServletException
  {
    super.init(sc);
try
    {
      Class.forName("sun.jdbc.odbc.JdbcOdbcDriver");
       con=DriverManager.getConnection("jdbc:odbc:aravind","scott","tiger");
 }catch(Exception e){  System.out.println(e);}
}
public void doGet(HttpServletRequest req,HttpServletResponse res)throws ServletException,IOException
{
               res.setContentType("text/html");
               PrintWriter pw=res.getWriter();
                     
               s1= req.getParameter("user");
               s2=req.getParameter("pwd");
     
    try{
          //accountno,usid,pwd,balance from transact where usid='"+s1+"'");  
          con.commit();
           Statement st=con.createStatement();
           ResultSet rs=st.executeQuery("select USER_ID,PUBLIC_KEY,ACCNO,BALANCE from auser where user_id='"+s1+"'");


     
           while(rs.next())
         {     
                //System.out.println(s1); System.out.println(s2); 

                  s3=rs.getString(1); 
                  s4=rs.getString(2); 
                 s5=rs.getString(3);                                                 //getString(3);
                 i=rs.getDouble(4);  
       
             /*   System.out.println("    "+rs.getString(1)); 
                System.out.println("    "+rs.getString(2));
                System.out.println("    "+rs.getString(3)); 
                System.out.println("    "+rs.getDouble(4));   */
             }       
              // System.out.println(s3); System.out.println(s4); 
          if(s3.equals(s1)&&s4.equals(s2))
                { 
                  System.out.println(s3); System.out.println(s4); 
                   Cookie uname=new Cookie("user",s1);
                   Cookie uaccno=new Cookie("acc",s5);  
 pw.println("<html><head><center>");
pw.println("<h2><u><b><i>WELCOME TO BANKING</i></b></u></h2></center>");
pw.println("</head><a href='http://localhost:8080/aboutus.html'>");
pw.println("<img src='http://localhost:8080/home2[1].gif' align=right></a>");
pw.println(" <body bgcolor=yellow  background='http://localhost:8080/backgrnd[2].gif'  text=red >");
pw.println(" <font face=arial size=5 color=blue><br><br>");
pw.println("<center><h3><i><b>STATEMENT</b></i></h3></center></font>");
pw.println(" <br><center>");
pw.println("<table border=22 bgcolor=yellow bordercolor=blue>");
pw.println("<tr><td bordercolor=blue bordercolorlight=maroon align=center >");
pw.println("<a href='http://localhost:8080/statement.html'>Statement</td>");
pw.println("<td  align=center>");
pw.println("<a href='http://localhost:8080/servlet/Client3' target=_top>Transaction</td>");
//transaction2 
pw.println("<td align=center>");
pw.println(" <a href='http://localhost:8080/usermanager.html'>UserManager</td>");
pw.println("<td align=center><a href='http://localhost:8080/logout.html' target=_top>Logout</td>");
pw.println("</tr></table>");
pw.println("<form ><center><pre>Name  :<input type=text name=t1 size=20 value="+s3+" DISABLED>");
pw.println("Account No"+"<input type=text name=t2 size=20 value="+s5+" DISABLED ><br>");
pw.println("<h4>The Balance in Your Account is RS :");
pw.println("<input type=text name=t3 value="+i+" DISABLED>");
pw.println("<br><br></center></pre><center><p>");
//pw.println("<input type=button name=b1 value=statement>");
//pw.println("<input type=button name=b2 value=Query>");
pw.println("</center></p></form></body></html>");
res.addCookie(uname); 
res.addCookie(uaccno);
}
else
    {
       res.sendRedirect("http://localhost:8080/invalid1.html");   
   }

//System.out.println(s3);         
}catch(Exception e1){ System.out.println(e1);}
}      
}
