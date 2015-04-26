/* DROP TRIGGER IF EXISTS `user_action_comment_times`; */
DELIMITER //
CREATE TRIGGER `user_action_comment_times` AFTER INSERT ON `comment`
FOR EACH ROW begin
  update clients set comment_num = comment_num+1 where id = new.userid;
end
//
DELIMITER ;

--
-- 事件，其实更推荐放到CT上，不要放在数据库里
--
DELIMITER $$
CREATE DEFINER=`root`@`localhost` EVENT `e_clean_authcode` ON SCHEDULE EVERY 10 DAY STARTS '2013-07-29 02:30:00' ON COMPLETION NOT PRESERVE ENABLE DO TRUNCATE TABLE `sms_authcode`$$
DELIMITER ;
