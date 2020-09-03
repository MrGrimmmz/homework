package test;

import dao.IUserDao;
import domain.AccountUser;
import domain.QueryVo;
import domain.QueryVoIds;
import domain.User;
import org.apache.ibatis.io.Resources;
import org.apache.ibatis.session.SqlSession;
import org.apache.ibatis.session.SqlSessionFactory;
import org.apache.ibatis.session.SqlSessionFactoryBuilder;
import org.junit.After;
import org.junit.Assert;
import org.junit.Before;
import org.junit.Test;
import org.omg.Messaging.SYNC_WITH_TRANSPORT;
import org.omg.PortableInterceptor.USER_EXCEPTION;

import java.io.InputStream;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;

public class UserDaoCRUDTest {
    private InputStream in;
    private SqlSessionFactory factory;
    private SqlSession session;
    private IUserDao userDao;

    @Before
    public void setUp() throws Exception {

        in = Resources.getResourceAsStream("SqlMapConfig.xml");

        SqlSessionFactoryBuilder builder = new SqlSessionFactoryBuilder();

        factory = builder.build(in);

        session = factory.openSession(true);

        userDao = session.getMapper(IUserDao.class);
    }

    @Test
    public void testFindOne() {

        User user = userDao.findById(41);
        System.out.println(user);
        Assert.assertEquals("张三",user.getUsername());
        //assert user.getUsername().equals("张三");
    }



    @Test
    public void testDeleteUser() {

            int res = userDao.deleteUser(60);
            Assert.assertEquals(1,res);
            //assert res == 1;
    }
    @Test
    public void testFindByName() {

        List<User> users = userDao.findByName("%王%");
        Assert.assertEquals(2,users.size());
        //assert users.size() == 2;
        for(User user : users) {
            System.out.println(user); } }
    @Test
    public void testFindByNameNew() {

        List<User> users = userDao.findByNameNew("王");
        Assert.assertEquals(2,users.size());

        for(User user : users){
            System.out.println(user); } }
    @Test
    public void testCount() {

        int res = userDao.count();
        Assert.assertEquals(8,res);
    }
    @Test
    public void testQueryByVo_withoutAddress() {
        QueryVo vo = new QueryVo();
        vo.setName("%王%");
        vo.setAddress(null);
        List<User> users = userDao.findByVo(vo);
        Assert.assertEquals(2,users.size());
        //assert users.size() == 2;
        }
    @Test
    public void testQueryByVo() {
        QueryVo vo = new QueryVo();
        vo.setName("%王%");
        vo.setAddress("%南京%");
        List<User> users = userDao.findByVo(vo);
        Assert.assertEquals(1,users.size());

    }

    @Test
    public void testFindInIds() {
        QueryVoIds voIds = new QueryVoIds();
        List<Integer> ids = new ArrayList<Integer>();
        ids.add(41);
        ids.add(42);
        ids.add(45);
        ids.add(46);
        voIds.setIds(ids);
        List<User> users = userDao.findInIds(voIds);
        Assert.assertEquals(4,users.size());
        //assert users.size() == 4;
        }

    @After
    public void tearDown() throws Exception {

        session.close();
        in.close();
    }



}