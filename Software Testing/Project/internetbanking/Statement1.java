import javax.servlet.*;
import javax.servlet.http.*;
import java.io.*;
import java.sql.*;

public class Statement1 extends HttpServlet
{
  
  Connection con;
 public void init(ServletConfig conf) throws ServletException
  {
    try{
      Class.forName("sun.jdbc.odbc.JdbcOdbcDriver");
      con=DriverManager.getConnection("jdbc:odbc:monalisa","scott","tiger");
       }catch(Exception e){System.out.println(e);}
   }
 public void doGet(HttpServletRequest req,HttpServletResponse res) throws ServletException,IOException
 {
   res.setContentType("text/html");
   PrintWriter pw=res.getWriter();
//   int accno=Integer.parseInt(req.getParameter("accno"));
    int accno=100;
    String dd1=req.getParameter("dd1");
    String mm1=req.getParameter("mm1");
    String yy1=req.getParameter("yy1");
    String sdate=dd1+"-"+mm1+"-"+yy1;
      
    String dd2=req.getParameter("dd2");
    String mm2=req.getParameter("mm2");
    String yy2=req.getParameter("yy2");
    String edate=dd2+"-"+mm2+"-"+yy2;


  try{
    PreparedStatement ps=con.prepareStatement("select *from atransact where transaction_date between '"+sdate+"' and '"+edate+"' and accno="+accno);
    ResultSet rs=ps.executeQuery();
    pw.println("<body bgcolor=red text=blue>"); 
    pw.println("<h2> Query Datails</h2>");
    pw.println("<table bgcolor=cyan border=2>");

    ResultSetMetaData rsmd=rs.getMetaData();

   for(int i=1;i<=rsmd.getColumnCount();i++)
    { 
       pw.println("<th>"+rsmd.getColumnName(i)+"</th>");
     }

    while(rs.next())
    {
      pw.println("<tr>");
     for(int i=1;i<=rsmd.getColumnCount();i++)
      {
          pw.println("<td>"+rs.getString(i)+"</td>");
     }
    pw.println("</tr>");
    }

    pw.println("</table></body>");
    }catch(Exception ee)
      {       System.out.println(ee);         }
  }
  }
 