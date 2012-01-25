<?php

//include_once "lib/captcha.php";



?>
<form action="" method="post">
<fieldset><legend><?=lang::translate('mail_form')?></legend>
<label for="title"><?=lang::translate('mail_form_title')?></label><br />
<input type="text" name="title" size="30" value="<?=@$_POST['title']?>" />
<br />
<label for="email"><?=lang::translate('mail_form_email')?></label><br />
<input type="text" name="email" size="30" value="<?=@$_POST['email']?>" />
<br />
<?php

    echo html::label('captcha', captcha::createCaptcha());
    echo html::text('captcha', @$_POST['captcha']);
?>

<label for="content"><?=lang::translate('mail_form_content')?></label><br />
<textarea name="content" cols="40" rows="20" ><?=@$_POST['content']?></textarea>
<label for="submit">&nbsp;</label>
<br />
<input type="submit" name="submit" value="<?=lang::translate('mail_form_submit')?>" />
<br />
</fieldset>

</form>

