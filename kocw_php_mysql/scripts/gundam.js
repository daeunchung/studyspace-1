$(document).ready(function(){
    $("header").click(function(){
        $("img").fadeIn(1000);
        $("p").fadeIn(1000);
    })
    // $("img").click(function(){
        // $(this).fadeOut(1000);
        // $(this).animate({marginLeft: '500px'}).animate({marginLeft: '0px'});
    //     $(this).animate({height: '+=30px', width: '+=30px'}).animate({height: '-=30px', width: '-=30px'});
    // })
    // $("img").hover(function(){
    //     $(this).animate({height: '+=30px', width: '+=30px', opacity: '0.5'}, 100);
    // },
    // function(){
    //     $(this).animate({height: '-=30px', width: '-=30px', opacity: '1.0'}, 100);
    // });
    $("p").click(function(){
        $(this).fadeOut(1000);
        // $(this).empty();
        // $(this).remove();
    })
    $("#btn_grade_desc").click(function(){
        if($(this).text() == "표시 안함"){
            $(this).text("표시");
        }else{
            $(this).text("표시 안함");
        }
        $(".grade_desc").slideToggle(1000);

        $("p").css({"background-color": "yellow", "padding": "16px"})
    });

    $(".grade_desc table").append("<tr><td>PG</td><td>Perfect Grade</td><td>1/60</td></tr>");
    // $(".grade_desc table tr").first().after("<tr><td>PG</td><td>Perfect Grade</td><td>1/60</td></tr>");

    $("h3").click(function(){   // h3의 형제들 : p태그, img태그
        // $(this).parent().empty();
        $(this).siblings().slideToggle(100);    
    });

    // $("#refresh").click(function(){
    //     // $(".model").append("테스트");
    //     $(".model").append('<article class="review">\
    //         <div class="img_frame">\
    //             <img class="user_image" src="images/hg.jpg" alt="Gundam Picture" />\
    //             <div class="user_memo"><p>무등급 1/100 건너 자쿠 워리어 - 루나마리아 전용 ZGMF-1000/A1</p></div>\
    //             <div class="user_info">\
    //                 <img class="user_thumbnail" src="images/face.jpg" alt="User Image" />\
    //                 <div class="user_email">a@l.com</div>\
    //                 <div class="user_date">2015년 12월 27일</div>\
    //             </div>\
    //         </div>\
    //     </article>');
    // });



    // listreview.php로 가서 xml파일로 리뷰 받아오기

    // $("#refresh").click(function(){
    //     // $(".model").empty();
    //     $.ajax({
    //         url: "listreview.php",
    //         cache: false,
    //         dataType: "xml",
    //         success: function(xml){
    //             $(xml).find("review").each(function(){
    //                 var review = '';
    //                 review += '<article class="review">\
    //                                 <div class="img_frame">\
    //                                     <img class="user_image" src=" ' + $(this).find("user_image").text() + '" alt="Gundam Picture" />';
    //                 review +=          '<div class="user_memo"><p>' + $(this).find("user_memo").text() + '</p></div>';
    //                 review +=          '<div class="user_info">\
    //                                          <img class="user_thumbnail" src="' + $(this).children("user_info").find("user_thumbnail").text() + '" alt="User Image" />';
    //                 review +=               '<div class="user_email">' + $(this).children("user_info").find("user_email").text() + '</div>';
    //                 review +=          '</div>';
    //                 review +=          '<div class="user_date">' + $(this).find("user_date").text() + '</div>';
    //                 review +=       '</div>';
    //                 review +=       '<section class="review_reply"></section>';
    //                 review +=   '</article>';

    //                 $(".model").append(review);
    //                 // alert($(this).children("user_info").find("user_thumbnail").text());
    //             });
    //         },
    //         error: function(xhr, ajaxOptions, thrownError){
    //             alert()
    //         }
    //     })
    // })


    
    // listreviewjson.php로 가서 json파일로 리뷰+댓글 받아오기
    refreshreview();
    $("#refresh").click(refreshreview);

    function refreshreview(){
        $.getJSON("listreviewjson.php", function(json){
            // alert(json.review.length);
            $(".review").remove();
            $.each(json.review, function(){
                    var review = '<article class="review">\
                                    <div class="img_frame">\
                                        <img class="user_image" src="getpicture.php?reviewid=' + this["reviewid"] + '" alt="Gundam Picture" />';
                    review +=          '<div class="user_memo"><p>' + this["memo"] + '</p></div>';
                    review +=          '<div class="user_info">\
                                             <img class="user_thumbnail" src="userimage.php?email=' + this["email"] + '" alt="User Image" />';
                    review +=               '<div class="user_email">' + this["email"] + '</div>';
                    review +=          '</div>';
                    review +=          '<div class="user_date">' + this["time"] + '</div>';
                    review +=       '</div>';
                    review +=       '<section class="review_reply">';
                    review +=       '<div id="write_reply"><a href="writereplyform.php?reviewid=' + this["reviewid"] + '">댓글 등록<a/></div>';

                    if(this.reply){
                        $.each(this.reply, function(){
                        var reply = '<article class="reply">';
                        reply +=    '<div class="user_reply"><p>' + this["memo"] + '</p></div>';
                        reply +=   '<div class="user_info">\
                        <img class="user_thumbnail" src="userimage.php?email=' + this["email"] + '" alt="User Image" />';
                        reply +=    '<div class="user_email">' + this["email"] + '</div>';
                        reply +=    '<div class="user_date">' + this["time"] + '</div>';
                        reply +=    '</div>';
                        reply +=    '</article>'; 

                        review += reply;
                        });
                    }
                    review +=   '</section>';
                    review +=   '</article>';

                    $(".model").append(review);
            });
        });
    }
})
